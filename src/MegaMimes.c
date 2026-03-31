#include "megamimes.h"
#include "megautil.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <sys/types.h>

#if defined(_WIN32)
  #include <io.h>
  #include <fcntl.h>
  #include <windows.h>
#else
  #include <unistd.h>
  #include <sys/stat.h>
  #include <fcntl.h>
#endif

/* forward decls from other units */
const char* mega_magic_detect(const uint8_t* buf, size_t n, const char** out_name);
const char* mega_ext_lookup(const char* path, const char** out_name);
bool        mega_is_text_and_encoding(const uint8_t* buf, size_t n, bool* out_is_text, const char** out_enc);

struct MegaMimesCtx {
  mega_alloc_t alloc;
  size_t       max_bytes;
  unsigned     flags;
  MegaMode     mode;
};

static size_t default_sample_bytes(size_t req) {
  return req ? req : (size_t)4096;
}

#define MEGA_STRICT_MIN_CONF 0.70f

typedef struct {
  MegaMimeCandidate items[8];
  size_t count;
} MegaCandidateList;

static void add_candidate(MegaCandidateList* list,
                          const char* mime,
                          float confidence,
                          MegaSource source)
{
  if (!list || !mime) return;
  if (list->count >= 8) return;
  list->items[list->count++] = (MegaMimeCandidate){
    .mime = mime,
    .confidence = confidence,
    .source = source
  };
}

static MegaMimeCandidate* select_best(MegaCandidateList* list) {
  if (!list || list->count == 0) return NULL;

  MegaMimeCandidate* best = &list->items[0];
  for (size_t i = 1; i < list->count; i++) {
    if (list->items[i].confidence > best->confidence) {
      best = &list->items[i];
    }
  }
  return best;
}

static float clamp_conf(float v) {
  if (v < 0.0f) return 0.0f;
  if (v > 1.0f) return 1.0f;
  return v;
}

static float adjusted_confidence(float base, MegaSource source, size_t sampled_bytes) {
  float c = base;
  if (source == MEGA_SRC_EXTENSION) {
    c *= 0.90f;
  }
  if (sampled_bytes > 0 && sampled_bytes < 4) {
    c *= 0.75f;
  }
  return clamp_conf(c);
}

static const char* source_to_string(MegaSource source) {
  switch (source) {
    case MEGA_SRC_MAGIC: return "magic";
    case MEGA_SRC_CONTAINER: return "container";
    case MEGA_SRC_EXTENSION: return "extension";
    default: return "unknown";
  }
}

static bool mime_eq(const char* a, const char* b) {
  return a && b && strcmp(a, b) == 0;
}

static const char* container_mime_for_path(const char* path, const char** out_name) {
  const char* ext = strrchr(path ? path : "", '.');
  if (!ext || !*(ext + 1)) return NULL;
  ext++;

#if defined(_WIN32)
  #define MEGA_STRCASECMP _stricmp
#else
  #define MEGA_STRCASECMP strcasecmp
#endif

  if (MEGA_STRCASECMP(ext, "docx") == 0) {
    if (out_name) *out_name = "DOCX";
    return "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
  }
  if (MEGA_STRCASECMP(ext, "xlsx") == 0) {
    if (out_name) *out_name = "XLSX";
    return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
  }
  if (MEGA_STRCASECMP(ext, "pptx") == 0) {
    if (out_name) *out_name = "PPTX";
    return "application/vnd.openxmlformats-officedocument.presentationml.presentation";
  }
  if (MEGA_STRCASECMP(ext, "odt") == 0) {
    if (out_name) *out_name = "ODT";
    return "application/vnd.oasis.opendocument.text";
  }
  if (MEGA_STRCASECMP(ext, "epub") == 0) {
    if (out_name) *out_name = "EPUB";
    return "application/epub+zip";
  }
  if (MEGA_STRCASECMP(ext, "jar") == 0) {
    if (out_name) *out_name = "JAR";
    return "application/java-archive";
  }
  return NULL;
}

MEGA_API MegaMimesCtx* mega_open(const MegaMimesConfig* cfg) {
  MegaMimesCtx* ctx = (MegaMimesCtx*)malloc(sizeof(*ctx));
  if (!ctx) return NULL;
  memset(ctx, 0, sizeof(*ctx));
  if (cfg) {
    ctx->alloc.xmalloc = cfg->xmalloc;
    ctx->alloc.xfree   = cfg->xfree;
    ctx->max_bytes     = default_sample_bytes(cfg->sample_bytes);
    ctx->flags         = cfg->flags;
    ctx->mode          = MEGA_MODE_NORMAL;
  } else {
    ctx->max_bytes     = default_sample_bytes(0);
    ctx->flags         = 0;
    ctx->mode          = MEGA_MODE_NORMAL;
  }
  return ctx;
}

MEGA_API void mega_set_mode(MegaMimesCtx* ctx, MegaMode mode) {
  if (!ctx) return;
  ctx->mode = mode;
}

MEGA_API void mega_set_max_bytes(MegaMimesCtx* ctx, size_t max_bytes) {
  if (!ctx) return;
  if (max_bytes < 256) max_bytes = 256;
  ctx->max_bytes = max_bytes;
}

MEGA_API void mega_close(MegaMimesCtx* ctx) {
  if (!ctx) return;
  free(ctx);
}

MEGA_API void mega_free(MegaMimesCtx* ctx, void* p) {
  (void)ctx; /* alloc hooks currently not per-ctx; reserved for future */
  free(p);
}

MEGA_API const char* mega_errstr(MegaMimesResult rc) {
  switch (rc) {
    case MEGA_OK:             return "ok";
    case MEGA_E_IO:           return "io error";
    case MEGA_E_INVALID_ARG:  return "invalid argument";
    case MEGA_E_NOMEM:        return "out of memory";
    case MEGA_E_UNSUPPORTED:  return "unsupported";
    default:                  return "unknown";
  }
}

static MegaMimesResult read_head_bytes(const char* path, size_t cap, uint8_t** out_buf, size_t* out_n, uint64_t* out_size) {
  *out_buf = NULL; *out_n = 0; if (out_size) *out_size = 0;

#if defined(_WIN32)
  HANDLE h = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  if (h == INVALID_HANDLE_VALUE) return MEGA_E_IO;
  LARGE_INTEGER sz;
  if (GetFileSizeEx(h, &sz) && out_size) *out_size = (uint64_t)sz.QuadPart;
  uint8_t* buf = (uint8_t*)malloc(cap);
  if (!buf) { CloseHandle(h); return MEGA_E_NOMEM; }
  DWORD rd = 0;
  if (!ReadFile(h, buf, (DWORD)cap, &rd, NULL)) { free(buf); CloseHandle(h); return MEGA_E_IO; }
  CloseHandle(h);
  *out_buf = buf; *out_n = (size_t)rd;
  return MEGA_OK;
#else
  int fd = open(path, O_RDONLY);
  if (fd < 0) return MEGA_E_IO;
  struct stat st;
  if (fstat(fd, &st) == 0 && out_size) *out_size = (uint64_t)st.st_size;
  uint8_t* buf = (uint8_t*)malloc(cap);
  if (!buf) { close(fd); return MEGA_E_NOMEM; }
  ssize_t rd = read(fd, buf, cap);
  if (rd < 0) { free(buf); close(fd); return MEGA_E_IO; }
  close(fd);
  *out_buf = buf; *out_n = (size_t)rd;
  return MEGA_OK;
#endif
}

MEGA_API MegaMimesResult mega_probe_path(MegaMimesCtx* ctx, const char* path, MegaFileInfo** out_info) {
  if (!ctx || !path || !out_info) return MEGA_E_INVALID_ARG;
  *out_info = NULL;

  uint8_t* head = NULL; size_t n = 0; uint64_t fsz = 0;
  MegaMimesResult rc = read_head_bytes(path, ctx->max_bytes, &head, &n, &fsz);
  if (rc != MEGA_OK) return rc;

  MegaCandidateList list;
  memset(&list, 0, sizeof(list));

  const char* magic_mime = NULL;
  const char* magic_name = NULL;
  const char* ext_mime = NULL;
  const char* ext_name = NULL;
  const char* container_mime = NULL;
  const char* container_name = NULL;
  int suspicious = 0;

  if (!(ctx->flags & MEGA_FLAG_EXT_ONLY)) {
    magic_mime = mega_magic_detect(head, n, &magic_name);
    if (magic_mime) {
      add_candidate(&list, magic_mime, adjusted_confidence(MEGA_CONF_MAGIC, MEGA_SRC_MAGIC, n), MEGA_SRC_MAGIC);
    }
  }

  if (magic_mime && strcmp(magic_mime, "application/zip") == 0) {
    container_mime = container_mime_for_path(path, &container_name);
    if (container_mime) {
      add_candidate(&list, container_mime, adjusted_confidence(MEGA_CONF_CONTAINER, MEGA_SRC_CONTAINER, n), MEGA_SRC_CONTAINER);
    }
  }

  ext_mime = mega_ext_lookup(path, &ext_name);
  if (ctx->mode != MEGA_MODE_STRICT && ext_mime) {
    add_candidate(&list, ext_mime, adjusted_confidence(MEGA_CONF_EXTENSION, MEGA_SRC_EXTENSION, n), MEGA_SRC_EXTENSION);
  }

  if (mime_eq(magic_mime, ext_mime)) {
    for (size_t i = 0; i < list.count; i++) {
      if (mime_eq(list.items[i].mime, magic_mime)) {
        list.items[i].confidence = clamp_conf(list.items[i].confidence + 0.03f);
      }
    }
  }
  if (magic_mime && ext_mime && !mime_eq(magic_mime, ext_mime)) {
    suspicious = 1;
  }

  if (ctx->mode == MEGA_MODE_STRICT) {
    int has_strong_signal = 0;
    for (size_t i = 0; i < list.count; i++) {
      if (list.items[i].source == MEGA_SRC_MAGIC || list.items[i].source == MEGA_SRC_CONTAINER) {
        has_strong_signal = 1;
        break;
      }
    }
    if (!has_strong_signal) {
      list.count = 0;
    }
  }

  MegaMimeCandidate* best = select_best(&list);
  if (ctx->mode == MEGA_MODE_STRICT && (!best || best->confidence < MEGA_STRICT_MIN_CONF)) {
    list.count = 0;
    best = NULL;
  }

  if (list.count > 0) {
    int has_strong_signal = 0;
    for (size_t i = 0; i < list.count; i++) {
      if (list.items[i].source == MEGA_SRC_MAGIC || list.items[i].source == MEGA_SRC_CONTAINER) {
        has_strong_signal = 1;
        break;
      }
    }
    if (!has_strong_signal) {
      suspicious = 1;
    }
  }

  bool is_text = false; const char* enc = NULL;
  (void)mega_is_text_and_encoding(head, n, &is_text, &enc);

  free(head);

  size_t extra = list.count * sizeof(MegaMimeCandidate);
  MegaFileInfo* info = (MegaFileInfo*)malloc(sizeof(*info) + extra);
  if (!info) return MEGA_E_NOMEM;
  memset(info, 0, sizeof(*info) + extra);

  if (list.count > 0) {
    info->candidates = (MegaMimeCandidate*)(info + 1);
    memcpy(info->candidates, list.items, extra);
    info->candidate_count = list.count;
  }

  info->path = path;
  info->size = fsz;
  info->mime_type = best ? best->mime : "application/octet-stream";
  info->confidence = best ? best->confidence : 0.0f;
  info->source = best ? source_to_string(best->source) : "none";
  if (best && best->source == MEGA_SRC_MAGIC && mime_eq(best->mime, magic_mime)) {
    info->mime_name = magic_name ? magic_name : best->mime;
  } else if (best && best->source == MEGA_SRC_CONTAINER && mime_eq(best->mime, container_mime)) {
    info->mime_name = container_name ? container_name : best->mime;
  } else if (best && best->source == MEGA_SRC_EXTENSION && mime_eq(best->mime, ext_mime)) {
    info->mime_name = ext_name ? ext_name : best->mime;
  } else {
    info->mime_name = best ? best->mime : "octet-stream";
  }
  info->suspicious = suspicious;
  info->is_text = is_text;
  info->text_encoding = enc;

  *out_info = info;
  return MEGA_OK;
}

MEGA_API MegaMimesResult mega_probe_fd(MegaMimesCtx* ctx, int fd, MegaFileInfo** out_info) {
  (void)ctx; (void)fd; (void)out_info;
  /* Minimal path-only version for now; fd-based read can be added next. */
  return MEGA_E_UNSUPPORTED;
}

#include "megamimes.h"
#include "megautil.h"
#include <stdio.h>
#include <string.h>
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
  size_t       sample_bytes;
  unsigned     flags;
};

static size_t default_sample_bytes(size_t req) {
  return req ? req : (size_t)65536;
}

MEGA_API MegaMimesCtx* mega_open(const MegaMimesConfig* cfg) {
  MegaMimesCtx* ctx = (MegaMimesCtx*)malloc(sizeof(*ctx));
  if (!ctx) return NULL;
  memset(ctx, 0, sizeof(*ctx));
  if (cfg) {
    ctx->alloc.xmalloc = cfg->xmalloc;
    ctx->alloc.xfree   = cfg->xfree;
    ctx->sample_bytes  = default_sample_bytes(cfg->sample_bytes);
    ctx->flags         = cfg->flags;
  } else {
    ctx->sample_bytes  = default_sample_bytes(0);
    ctx->flags         = 0;
  }
  return ctx;
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
  MegaMimesResult rc = read_head_bytes(path, ctx->sample_bytes, &head, &n, &fsz);
  if (rc != MEGA_OK) return rc;

  const char* mime = NULL; const char* mname = NULL; const char* src = "extension";

  if (!(ctx->flags & MEGA_FLAG_EXT_ONLY)) {
    mime = mega_magic_detect(head, n, &mname);
    if (mime) src = "magic";
  }
  if (!mime) {
    mime = mega_ext_lookup(path, &mname);
    src = "extension";
  }
  bool is_text = false; const char* enc = NULL;
  (void)mega_is_text_and_encoding(head, n, &is_text, &enc);

  free(head);

  MegaFileInfo* info = (MegaFileInfo*)malloc(sizeof(*info));
  if (!info) return MEGA_E_NOMEM;
  memset(info, 0, sizeof(*info));
  info->path = path;
  info->size = fsz;
  info->mime_type = mime ? mime : "application/octet-stream";
  info->mime_name = mname ? mname : (mime ? mime : "octet-stream");
  info->source = src;
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

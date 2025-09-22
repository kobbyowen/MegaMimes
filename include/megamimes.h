#ifndef MEGAMIMES_H
#define MEGAMIMES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#if defined(_WIN32) && defined(MEGA_BUILD_DLL)
  #define MEGA_API __declspec(dllexport)
#elif defined(_WIN32)
  #define MEGA_API __declspec(dllimport)
#else
  #define MEGA_API __attribute__((visibility("default")))
#endif

typedef enum {
  MEGA_OK = 0,
  MEGA_E_IO,
  MEGA_E_INVALID_ARG,
  MEGA_E_NOMEM,
  MEGA_E_UNSUPPORTED,
  MEGA_E_UNKNOWN
} MegaMimesResult;

typedef struct {
  const char* override_file;   /* reserved for future: runtime mime overrides */
  size_t      sample_bytes;    /* how many bytes to sample from head; 0=default(65536) */
  unsigned    flags;           /* bitmask: see MEGA_FLAG_* */
  void* (*xmalloc)(size_t);    /* optional custom allocators */
  void  (*xfree)(void*);
} MegaMimesConfig;

/* flags */
enum {
  MEGA_FLAG_EXT_ONLY   = 1u << 0,   /* skip magic signatures */
  MEGA_FLAG_NO_FOLLOW  = 1u << 1,   /* do not follow symlinks (platform dependent) */
  MEGA_FLAG_SAMPLE_TAIL= 1u << 2    /* (future) also sample tail bytes */
};

typedef struct MegaMimesCtx MegaMimesCtx;

typedef struct {
  /* file identity */
  const char* path;           /* borrowed pointer, may be NULL for fd-based probe */
  uint64_t    size;           /* 0 if unknown */
  /* classification */
  const char* mime_type;      /* e.g., "application/pdf" */
  const char* mime_name;      /* short name, e.g., "PDF" */
  const char* source;         /* "magic", "container", "extension" */
  /* text/binary */
  bool        is_text;
  const char* text_encoding;  /* "UTF-8", "UTF-16LE", etc., or NULL */
} MegaFileInfo;

/* Lifecycle */
MEGA_API MegaMimesCtx*   mega_open(const MegaMimesConfig* cfg);
MEGA_API void            mega_close(MegaMimesCtx* ctx);

/* Probing */
MEGA_API MegaMimesResult mega_probe_path(MegaMimesCtx* ctx, const char* path, MegaFileInfo** out_info);
MEGA_API MegaMimesResult mega_probe_fd  (MegaMimesCtx* ctx, int fd, MegaFileInfo** out_info);

/* Utility */
MEGA_API const char*     mega_errstr(MegaMimesResult rc);

/* Memory release for structs allocated via ctx allocators */
MEGA_API void            mega_free(MegaMimesCtx* ctx, void* p);

#ifdef __cplusplus
}
#endif

#endif /* MEGAMIMES_H */

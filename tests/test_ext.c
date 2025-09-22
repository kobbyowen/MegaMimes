#include "megamimes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "test_helpers.h"

static int probe_text_file_with_ext(const char* ext, const char* expect_mime) {
  MegaMimesConfig cfg = {0};
  cfg.flags = MEGA_FLAG_EXT_ONLY;   // <-- use enum from header
  MegaMimesCtx* ctx = mega_open(&cfg);
  if (!ctx) { fprintf(stderr, "ctx init failed\n"); return 1; }

  char* path = write_temp_text_with_ext("mm-ext", ext, "hello\n");
  if (!path) { fprintf(stderr, "temp path failed\n"); mega_close(ctx); return 1; }

  MegaFileInfo* info = NULL;
  MegaMimesResult rc = mega_probe_path(ctx, path, &info);
  int fail = 0;

  if (rc != MEGA_OK) {
    fprintf(stderr, "probe rc=%d (%s)\n", rc, mega_errstr(rc));
    fail = 1;
  } else if (strcmp(info->mime_type, expect_mime)!=0) {
    fprintf(stderr, "ext=%s path=%s\n", ext, path);
    fprintf(stderr, "expected mime=%s but got mime=%s (source=%s)\n",
            expect_mime, info->mime_type, info->source ? info->source : "?");
    fail = 1;
  }

  free(path);
  mega_free(ctx, info);
  mega_close(ctx);
  return fail;
}

int test_ext_suite(void) {
  int fails = 0;
  fails += probe_text_file_with_ext("txt",  "text/plain");
  fails += probe_text_file_with_ext("md",   "text/markdown");
  fails += probe_text_file_with_ext("html", "text/html");
  fails += probe_text_file_with_ext("json", "application/json");
  fails += probe_text_file_with_ext("png",  "image/png");
  return fails;
}

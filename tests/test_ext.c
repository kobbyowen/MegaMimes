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

static int extension_only_is_low_confidence(void) {
  MegaMimesConfig cfg = {0};
  cfg.flags = MEGA_FLAG_EXT_ONLY;
  MegaMimesCtx* ctx = mega_open(&cfg);
  if (!ctx) return 1;

  char* path = write_temp_text_with_ext("mm-ext-low", "txt", "hello\n");
  if (!path) { mega_close(ctx); return 1; }

  MegaFileInfo* info = NULL;
  MegaMimesResult rc = mega_probe_path(ctx, path, &info);
  int fail = (rc != MEGA_OK)
    || strcmp(info->mime_type, "text/plain") != 0
    || info->confidence >= 0.50f
    || strcmp(info->source, "extension") != 0;

  free(path);
  mega_free(ctx, info);
  mega_close(ctx);
  return fail;
}

static int mismatch_marks_suspicious(void) {
  const unsigned char pdf[] = {'%','P','D','F','-','1','.','7','\n'};
  MegaMimesCtx* ctx = mega_open(NULL);
  if (!ctx) return 1;

  char* path = write_temp_bytes_with_ext("mm-mismatch", "txt", pdf, sizeof(pdf));
  if (!path) { mega_close(ctx); return 1; }

  MegaFileInfo* info = NULL;
  MegaMimesResult rc = mega_probe_path(ctx, path, &info);
  int fail = (rc != MEGA_OK)
    || strcmp(info->mime_type, "application/pdf") != 0
    || info->suspicious != 1;

  free(path);
  mega_free(ctx, info);
  mega_close(ctx);
  return fail;
}

static int strict_rejects_extension_only(void) {
  MegaMimesConfig cfg = {0};
  cfg.flags = MEGA_FLAG_EXT_ONLY;
  MegaMimesCtx* ctx = mega_open(&cfg);
  if (!ctx) return 1;
  mega_set_mode(ctx, MEGA_MODE_STRICT);

  char* path = write_temp_text_with_ext("mm-strict-ext", "txt", "hello\n");
  if (!path) { mega_close(ctx); return 1; }

  MegaFileInfo* info = NULL;
  MegaMimesResult rc = mega_probe_path(ctx, path, &info);
  int fail = (rc != MEGA_OK)
    || strcmp(info->mime_type, "application/octet-stream") != 0
    || info->confidence != 0.0f
    || info->candidate_count != 0;

  free(path);
  mega_free(ctx, info);
  mega_close(ctx);
  return fail;
}

static int strict_accepts_magic(void) {
  const unsigned char pdf[] = {'%','P','D','F','-','1','.','7','\n'};
  MegaMimesCtx* ctx = mega_open(NULL);
  if (!ctx) return 1;
  mega_set_mode(ctx, MEGA_MODE_STRICT);

  char* path = write_temp_bytes_with_ext("mm-strict-magic", "bin", pdf, sizeof(pdf));
  if (!path) { mega_close(ctx); return 1; }

  MegaFileInfo* info = NULL;
  MegaMimesResult rc = mega_probe_path(ctx, path, &info);
  int fail = (rc != MEGA_OK)
    || strcmp(info->mime_type, "application/pdf") != 0
    || info->confidence < 0.70f;

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
  fails += extension_only_is_low_confidence();
  fails += mismatch_marks_suspicious();
  fails += strict_rejects_extension_only();
  fails += strict_accepts_magic();
  return fails;
}

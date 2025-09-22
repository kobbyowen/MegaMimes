#include "megamimes.h"
#include <string.h>
#include <stdlib.h>
#include "test_helpers.h"
static int probe_bytes(const unsigned char* b, size_t n, int* out_is_text, const char** out_enc) {
  MegaMimesCtx* ctx = mega_open(NULL);
  if (!ctx) return 1;
  char* path = write_temp_bytes("mm-text", b, n);
  if (!path) { mega_close(ctx); return 1; }
  MegaFileInfo* info = NULL;
  int rc = mega_probe_path(ctx, path, &info);
  int fail = (rc != MEGA_OK);
  if (!fail) { if (out_is_text) *out_is_text = info->is_text; if (out_enc) *out_enc = info->text_encoding; }
  free(path); mega_free(ctx, info); mega_close(ctx);
  return fail;
}
int test_text_suite(void) {
  int fails = 0; int is_text=0; const char* enc=NULL;
  const unsigned char ascii[] = "hello world\n";
  fails += probe_bytes(ascii, sizeof(ascii)-1, &is_text, &enc);
  if (!(is_text)) fails++;
  return fails;
}
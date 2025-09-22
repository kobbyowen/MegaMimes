#include "megamimes.h"
#include <string.h>
#include <stdlib.h>
#include "test_helpers.h"
static int assert_mime(const unsigned char* bytes, size_t n, const char* expect) {
  MegaMimesCtx* ctx = mega_open(NULL);
  if (!ctx) return 1;
  char* path = write_temp_bytes("mm-magic", bytes, n);
  if (!path) { mega_close(ctx); return 1; }
  MegaFileInfo* info = NULL;
  int rc = mega_probe_path(ctx, path, &info);
  int fail = (rc != MEGA_OK) || strcmp(info->mime_type, expect) != 0;
  free(path); mega_free(ctx, info); mega_close(ctx);
  return fail;
}
int test_magic_suite(void) {
  int fails = 0;
  const unsigned char pdf[] = {'%','P','D','F','-','1','.','7','\n'};
  fails += assert_mime(pdf, sizeof(pdf), "application/pdf");
  return fails;
}
#include <stdio.h>
int test_magic_suite(void);
int test_ext_suite(void);
int test_text_suite(void);
static int run_suite(const char* name, int (*fn)(void)) {
  int rc = fn();
  printf("[TEST] %s: %s\n", name, rc==0 ? "OK" : "FAIL");
  return rc;
}
int main(void) {
  int failures = 0;
  failures += run_suite("magic", test_magic_suite);
  failures += run_suite("extension", test_ext_suite);
  failures += run_suite("text", test_text_suite);
  return failures ? 1 : 0;
}
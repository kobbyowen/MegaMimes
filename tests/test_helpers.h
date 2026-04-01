#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

static inline char* test_helpers_strdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* copy = (char*)malloc(len);
  if (!copy) return NULL;
  memcpy(copy, s, len);
  return copy;
}

static inline char* make_temp_path(const char* base) {
#ifdef _WIN32
  char temp_dir[MAX_PATH];
  char temp_path[MAX_PATH];
  char prefix[4] = {'m', 'm', 'm', '\0'};
  DWORD dir_len = GetTempPathA((DWORD)sizeof(temp_dir), temp_dir);
  size_t i;

  if (dir_len == 0 || dir_len > sizeof(temp_dir) - 1) return NULL;
  for (i = 0; i < 3 && base[i]; ++i) {
    prefix[i] = base[i];
  }

  if (GetTempFileNameA(temp_dir, prefix, 0, temp_path) == 0) return NULL;
  return test_helpers_strdup(temp_path);
#else
  const char* temp_dir = getenv("TMPDIR");
  char tmpl[512];
  int fd;

  if (!temp_dir || !temp_dir[0]) temp_dir = "/tmp";
  snprintf(tmpl, sizeof(tmpl), "%s/%s-XXXXXX", temp_dir, base);
  fd = mkstemp(tmpl);
  if (fd < 0) return NULL;
  close(fd);
  return test_helpers_strdup(tmpl);
#endif
}

static inline char* make_temp_path_with_ext(const char* base, const char* ext) {
  char* temp_path = make_temp_path(base);
  char* path;

  if (!temp_path) return NULL;
  path = (char*)malloc(strlen(temp_path) + strlen(ext) + 2);
  if (!path) {
    remove(temp_path);
    free(temp_path);
    return NULL;
  }

  sprintf(path, "%s.%s", temp_path, ext);
  if (rename(temp_path, path) != 0) {
    remove(temp_path);
    free(temp_path);
    free(path);
    return NULL;
  }

  free(temp_path);
  return path;
}

static inline char* write_temp_bytes(const char* base, const unsigned char* data, size_t n) {
  char* path = make_temp_path(base);
  FILE* f;

  if (!path) return NULL;
  f = fopen(path, "wb");
  if (!f) {
    remove(path);
    free(path);
    return NULL;
  }

  fwrite(data, 1, n, f);
  fclose(f);
  return path;
}

static inline char* write_temp_text_with_ext(const char* base, const char* ext, const char* s) {
  char* path = make_temp_path_with_ext(base, ext);
  FILE* f;

  if (!path) return NULL;
  f = fopen(path, "wb");
  if (!f) {
    remove(path);
    free(path);
    return NULL;
  }

  fputs(s, f);
  fclose(f);
  return path;
}

static inline char* write_temp_bytes_with_ext(const char* base, const char* ext, const unsigned char* data, size_t n) {
  char* path = make_temp_path_with_ext(base, ext);
  FILE* f;

  if (!path) return NULL;
  f = fopen(path, "wb");
  if (!f) {
    remove(path);
    free(path);
    return NULL;
  }

  fwrite(data, 1, n, f);
  fclose(f);
  return path;
}
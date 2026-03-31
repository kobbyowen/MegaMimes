#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static inline char* write_temp_bytes(const char* base, const unsigned char* data, size_t n) {
  char tmpl[256]; snprintf(tmpl, sizeof(tmpl), "/tmp/%s-XXXXXX", base);
  int fd = mkstemp(tmpl); if (fd<0) return NULL;
  FILE* f = fdopen(fd,"wb"); if(!f){close(fd);return NULL;}
  fwrite(data,1,n,f); fclose(f);
  return strdup(tmpl);
}
static inline char* write_temp_text_with_ext(const char* base,const char* ext,const char* s){
  char tmpl[256]; snprintf(tmpl,sizeof(tmpl),"/tmp/%s-XXXXXX",base);
  int fd=mkstemp(tmpl); if(fd<0) return NULL; close(fd);
  char* path=(char*)malloc(strlen(tmpl)+strlen(ext)+2);
  sprintf(path,"%s.%s",tmpl,ext);
  FILE* f=fopen(path,"wb"); if(!f){free(path);return NULL;}
  fputs(s,f); fclose(f);
  return path;
}

static inline char* write_temp_bytes_with_ext(const char* base, const char* ext, const unsigned char* data, size_t n) {
  char tmpl[256]; snprintf(tmpl, sizeof(tmpl), "/tmp/%s-XXXXXX", base);
  int fd = mkstemp(tmpl); if (fd < 0) return NULL; close(fd);
  char* path = (char*)malloc(strlen(tmpl) + strlen(ext) + 2);
  if (!path) return NULL;
  sprintf(path, "%s.%s", tmpl, ext);
  FILE* f = fopen(path, "wb"); if (!f) { free(path); return NULL; }
  fwrite(data, 1, n, f);
  fclose(f);
  return path;
}
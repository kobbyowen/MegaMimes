#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MEGA_MIN(a,b) ((a)<(b)?(a):(b))
#define MEGA_MAX(a,b) ((a)>(b)?(a):(b))

typedef struct {
  void* (*xmalloc)(size_t);
  void  (*xfree)(void*);
} mega_alloc_t;

static inline void* mega_xmalloc(mega_alloc_t* a, size_t n) {
  void* p = (a && a->xmalloc) ? a->xmalloc(n) : malloc(n);
  return p;
}
static inline void  mega_xfree(mega_alloc_t* a, void* p) {
  if (!p) return;
  if (a && a->xfree) a->xfree(p); else free(p);
}

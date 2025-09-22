#include "megamimes.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <file> [--json]\n", argv[0]);
    return 2;
  }
  int json = (argc >= 3 && strcmp(argv[2],"--json")==0);
  MegaMimesCtx* ctx = mega_open(NULL);
  if (!ctx) { fprintf(stderr, "megamimes: init failed\n"); return 1; }

  MegaFileInfo* info = NULL;
  MegaMimesResult rc = mega_probe_path(ctx, argv[1], &info);
  if (rc != MEGA_OK) {
    fprintf(stderr, "probe error: %s\n", mega_errstr(rc));
    mega_close(ctx);
    return 1;
  }

  if (json) {
    printf("{\"path\":\"%s\",\"size\":%llu,\"mime\":\"%s\",\"name\":\"%s\",\"source\":\"%s\",\"text\":%s,\"encoding\":%s}\n",
      info->path?info->path:"",
      (unsigned long long)info->size,
      info->mime_type?info->mime_type:"application/octet-stream",
      info->mime_name?info->mime_name:"",
      info->source?info->source:"",
      info->is_text? "true":"false",
      info->text_encoding? "\"":"");
    if (info->text_encoding) printf("%s\"}\n", info->text_encoding);
    else printf("null}\n");
  } else {
    printf("Path: %s\n", info->path?info->path:"(fd)");
    printf("Size: %llu bytes\n", (unsigned long long)info->size);
    printf("MIME: %s (%s) via %s\n",
      info->mime_type?info->mime_type:"application/octet-stream",
      info->mime_name?info->mime_name:"", info->source?info->source:"");
    printf("Text: %s", info->is_text? "yes":"no");
    if (info->is_text && info->text_encoding) printf(" (%s)", info->text_encoding);
    printf("\n");
  }

  mega_free(ctx, info);
  mega_close(ctx);
  return 0;
}

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

static bool has_prefix(const uint8_t* b, size_t n, const char* s) {
  size_t m = strlen(s);
  return n >= m && memcmp(b, s, m) == 0;
}
static bool bytes_eq(const uint8_t* b, size_t n, const uint8_t* sig, size_t m) {
  return n >= m && memcmp(b, sig, m) == 0;
}
static bool riff_webp(const uint8_t* b, size_t n) {
  return n >= 12 && memcmp(b, "RIFF", 4) == 0 && memcmp(b+8, "WEBP", 4) == 0;
}
static bool mp4_ftyp(const uint8_t* b, size_t n) {
  if (n < 12) return false;
  /* box size(4) + 'ftyp'(4) + major brand(4) */
  uint32_t boxsize = (b[0]<<24)|(b[1]<<16)|(b[2]<<8)|b[3];
  if (boxsize < 8 || memcmp(b+4, "ftyp", 4) != 0) return false;
  return true;
}
static bool mp3_sig(const uint8_t* b, size_t n) {
  return (n >= 3 && memcmp(b, "ID3", 3) == 0) ||
         (n >= 2 && b[0] == 0xFF && (b[1] & 0xE0) == 0xE0);
}

const char* mega_magic_detect(const uint8_t* b, size_t n, const char** out_name) {
  static const uint8_t PNG[]  = {0x89,'P','N','G',0x0D,0x0A,0x1A,0x0A};
  static const uint8_t JPG[]  = {0xFF,0xD8,0xFF};
  static const uint8_t GIF87[]= {'G','I','F','8','7','a'};
  static const uint8_t GIF89[]= {'G','I','F','8','9','a'};
  static const uint8_t ZIP[]  = {0x50,0x4B,0x03,0x04};
  static const uint8_t PDF[]  = {'%','P','D','F','-'};
  static const uint8_t ELF[]  = {0x7F,'E','L','F'};
  static const uint8_t MZ[]   = {'M','Z'};

  if (bytes_eq(b,n, PDF, sizeof(PDF)))  { if(out_name)*out_name="PDF";  return "application/pdf"; }
  if (bytes_eq(b,n, PNG, sizeof(PNG)))  { if(out_name)*out_name="PNG";  return "image/png"; }
  if (bytes_eq(b,n, JPG, sizeof(JPG)))  { if(out_name)*out_name="JPEG"; return "image/jpeg"; }
  if (bytes_eq(b,n, GIF87,sizeof(GIF87))||bytes_eq(b,n,GIF89,sizeof(GIF89))) { if(out_name)*out_name="GIF"; return "image/gif"; }
  if (riff_webp(b,n))                   { if(out_name)*out_name="WebP"; return "image/webp"; }
  if (mp4_ftyp(b,n))                    { if(out_name)*out_name="MP4";  return "video/mp4"; }
  if (mp3_sig(b,n))                     { if(out_name)*out_name="MP3";  return "audio/mpeg"; }
  if (bytes_eq(b,n, ZIP, sizeof(ZIP)))  { if(out_name)*out_name="ZIP";  return "application/zip"; }
  if (bytes_eq(b,n, ELF, sizeof(ELF)))  { if(out_name)*out_name="ELF";  return "application/x-elf"; }
  if (bytes_eq(b,n, MZ,  sizeof(MZ)))   { if(out_name)*out_name="PE";   return "application/vnd.microsoft.portable-executable"; }

  /* Soft JSON heuristic: leading whitespace then '{' or '[' and likely UTF-8 */
  size_t i=0; while (i<n && (b[i]==0x20||b[i]==0x09||b[i]==0x0A||b[i]==0x0D)) i++;
  if (i<n && (b[i]=='{' || b[i]=='[')) { if(out_name)*out_name="JSON"; return "application/json"; }

  return NULL;
}

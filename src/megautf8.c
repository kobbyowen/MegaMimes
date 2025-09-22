#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* returns encoding string if BOM found */
static const char* bom_encoding(const uint8_t* b, size_t n) {
  if (n>=3 && b[0]==0xEF&&b[1]==0xBB&&b[2]==0xBF) return "UTF-8";
  if (n>=2 && b[0]==0xFF&&b[1]==0xFE)             return "UTF-16LE";
  if (n>=2 && b[0]==0xFE&&b[1]==0xFF)             return "UTF-16BE";
  if (n>=4 && b[0]==0xFF&&b[1]==0xFE&&b[2]==0x00&&b[3]==0x00) return "UTF-32LE";
  if (n>=4 && b[0]==0x00&&b[1]==0x00&&b[2]==0xFE&&b[3]==0xFF) return "UTF-32BE";
  return NULL;
}

/* minimal UTF-8 validator (byte-class DFA) */
static bool utf8_valid(const uint8_t* s, size_t n) {
  size_t i=0;
  while (i<n) {
    uint8_t c = s[i];
    if (c < 0x80) { i++; continue; }
    else if ((c >> 5) == 0x6) { /* 110x xxxx */
      if (i+1>=n) return false;
      if ((s[i+1] & 0xC0) != 0x80) return false;
      i+=2;
    } else if ((c >> 4) == 0xE) { /* 1110 xxxx */
      if (i+2>=n) return false;
      if ((s[i+1] & 0xC0) != 0x80 || (s[i+2] & 0xC0) != 0x80) return false;
      i+=3;
    } else if ((c >> 3) == 0x1E) { /* 1111 0xxx (UTF-8 up to 4 bytes) */
      if (i+3>=n) return false;
      if ((s[i+1] & 0xC0) != 0x80 || (s[i+2] & 0xC0) != 0x80 || (s[i+3] & 0xC0) != 0x80) return false;
      i+=4;
    } else return false;
  }
  return true;
}

bool mega_is_text_and_encoding(const uint8_t* buf, size_t n, bool* out_is_text, const char** out_enc) {
  const char* enc = bom_encoding(buf, n);
  if (out_enc) *out_enc = enc;

  /* quick binary check: presence of NUL or many control chars */
  size_t ctrl = 0, bytes = n < 4096 ? n : 4096;
  for (size_t i=0;i<bytes;i++) {
    uint8_t c = buf[i];
    if (c==0) { if(out_is_text) *out_is_text=false; return false; }
    if (c < 0x09 || (c>0x0D && c<0x20)) ctrl++;
  }
  if (ctrl > bytes/8) { if(out_is_text) *out_is_text=false; return false; }

  if (enc) { if(out_is_text) *out_is_text=true; return true; }
  bool utf8 = utf8_valid(buf, bytes);
  if (out_enc) *out_enc = utf8 ? "UTF-8" : NULL;
  if (out_is_text) *out_is_text = utf8 || ctrl == 0;
  return true;
}

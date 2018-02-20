#include "scan.h"

unsigned int scan_8long(const char *src,unsigned long *dest) {
  register const char *tmp=src;
  register int l=0;
  register unsigned char c;
  while((c=*tmp-'0')<8) {
    l=l*8+c;
    ++tmp;
  }
  *dest=l;
  return tmp-src;
}

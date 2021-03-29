#include "../../lib/fmt.h"
#include "../source.h"

size_t
fmt_loc(char* dest, const struct location* loc) {
  char* p = dest;
  p += fmt_uint(p, loc->line);
  *p++ = ':';
  p += fmt_uint(p, loc->column);
  return p - dest;
}
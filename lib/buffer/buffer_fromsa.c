#include "stralloc.h"
#include "buffer.h"

ssize_t
buffer_dummyread(int fd, char* buf, size_t len) {
  return 0;
}

void
buffer_fromsa(buffer* b, stralloc* sa) {
  b->x = sa->s;
  b->p = 0;
  b->n = sa->len;
  b->a = sa->a;
  b->fd = -1;
  b->op = buffer_dummyread;
}

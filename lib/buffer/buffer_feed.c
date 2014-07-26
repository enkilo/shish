#include "buffer.h"

extern ssize_t buffer_stubborn_read(ssize_t (*op)(),int fd,const char* buf, unsigned int len);

int buffer_feed(buffer* b) {
  if (b->p==b->n) {
    int w;
    if ((w=buffer_stubborn_read(b->op,b->fd,b->x,b->a))<0)
      return -1;
    b->n=w;
    b->p=0;
  }
  return (b->n-b->p);
}

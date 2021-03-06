#include "../fd.h"

/* check if an (fd) needs buffer space
 * ----------------------------------------------------------------------- */
int
fd_needbuf(struct fd* fd) {
  if(FD_ISRD(fd) && !fd->r->x)
    return 1;

  if(FD_ISWR(fd) && !fd->w->x)
    return 1;

  return 0;
}

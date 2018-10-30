#include "byte.h"
#include "fdstack.h"
#include "fd.h"

/* unreference buffer pointers of any duplicates of the olddup fd
 * 
 * returns number of dupes we had
 * ----------------------------------------------------------------------- */
unsigned int fdstack_unref(struct fd *olddup) {
  struct fdstack *st;
  struct fd *fd;
  struct fd *newdup = NULL;
  unsigned int n = 0;

  for(st = fdstack; st; st = st->parent)
    for(fd = st->list; fd; fd = fd->next) {
    /* consider only fds which are a duplicate of olddup */
    if(fd->dup != olddup || fd == olddup)
      continue;
    
    n++;
    
    /* move buffer stuff to the first found duplicate */
      if(newdup == NULL) {
      byte_copy(&fd->rb, FD_SIZE, olddup->r);
      byte_copy(&fd->wb, FD_SIZE, olddup->w);
      
      olddup->rb.fd = -1; olddup->rb.x = NULL;
      olddup->wb.fd = -1; olddup->wb.x = NULL;
      
      fd->r = &fd->rb;
      fd->w = &fd->wb;
      
      /* give up temporary buffers */
        if(olddup->mode & FD_TMPBUF) {
        buffer_free(&fd->rb);
        buffer_free(&fd->wb);
      }
      
      newdup = fd;
      
      continue;
    }
    
    /* set buffer pointers to the new duplicatee */
    fd->r = newdup->r;
    fd->w = newdup->w;
  }
  
  return n;
}

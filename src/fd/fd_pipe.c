#include "../fd.h"
#include "../fdtable.h"
#include "../sh.h"
#include "../debug.h"
#include "../../lib/windoze.h"

#if WINDOWS_NATIVE
#define pipe(f) _pipe(f, 0, 0)
#else
#include <unistd.h>
#endif

/* create a pipe
 * ----------------------------------------------------------------------- */
int
fd_pipe(struct fd* fd) {
  int p[2];
  int e;

  /* try to create a pipe and return on error */
  if(pipe(p) == -1) {
    sh_error("pipe creation failed");
    return -1;
  }

  /* create new (fd) for the pipe */
  fd->name = "<pipe>";
  fd->mode |= FD_PIPE;

  fdtable_track(p[0], FDTABLE_LAZY);
  fdtable_track(p[1], FDTABLE_LAZY);

  /* set up the file descriptors */
  if(FD_ISWR(fd)) {
    fd_setfd(fd, p[1]);
    e = p[0];
  } else {
    fd_setfd(fd, p[0]);
    e = p[1];
  }

#if defined(DEBUG_OUTPUT) && defined(DEBUG_FD)
  buffer_puts(debug_output, "fd_pipe n=");
  buffer_putlong(debug_output, fd->n);
  buffer_puts(debug_output, " e=");
  buffer_putlong(debug_output, fd->e);
  buffer_puts(debug_output, " ret=");
  buffer_putlong(debug_output, e);
  debug_nl_fl();
#endif

  return e;
}

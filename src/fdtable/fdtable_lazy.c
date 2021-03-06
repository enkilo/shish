#include "../fd.h"
#include "../fdtable.h"
#include "../../lib/windoze.h"
#if WINDOWS_NATIVE
#include <io.h>
#else
#include <unistd.h>
#endif

/* try to lazy-resolve fds until the supplied fd is the bottom
 * ----------------------------------------------------------------------- */
int
fdtable_lazy(int e, int flags) {
  struct fd* fd;
  int r;

  while((e != fd_expected) && (fd = fdtable[fd_expected])) {
    /* try to resolve the current expected efd */
    r = fdtable_resolve(fd, flags);

    /* return if we got the wished bottom */
    if(fd_ok(r) || r == FDTABLE_DONE)
      return r;

    /* if we cannot continue filling up the table, finish for now */
    if(r == FDTABLE_PENDING)
      break;
  }

  return (e == fd_expected ? FDTABLE_DONE : FDTABLE_PENDING);
}

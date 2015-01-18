#include "fdtable.h"
#include "fd.h"

/* should always be called just after the kernel gives you a new
 * file handle. it is to track the lowest available file descriptor
 * to optimize redirections.
 * ----------------------------------------------------------------------- */
void fdtable_track(int n, int flags)
{
  if(n < fd_exp) fd_exp = n;
  if(n > fd_exp) fdtable_unexpected(fd_exp, n, flags);
  
  fdtable_up();
}

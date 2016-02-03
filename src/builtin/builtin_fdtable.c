<<<<<<< HEAD
#ifndef WIN32
=======
#ifdef _WIN32
#include <io.h>
#else
>>>>>>> 6c7455723b47a4989fb5bb621be8f200a306f361
#include <unistd.h>
#endif
#include "sh.h"
#include "fd.h"
#include "fdtable.h"
#include "builtin.h"

/* fdtable built-in - shows open files and stuff
 * 
 * note that the virtual file descriptor 's' is the source which the shell
 * parses (which may obviously differ from stdin).
 * 
 * an effective filedescriptor of "m" means that the fd is
 * memory-mapped
 * 
 * "b" for effective filedescriptor means that the fd has been 
 * redirected to an internal write-buffer (for command substitution) or
 * redirected from an internal read-buffer (for the here-docs).
 * ----------------------------------------------------------------------- */
int builtin_fdtable(int argc, char **argv)
{
  int i;

  buffer_puts(fd_out->w, " vfd  rfd  wfd  lev  file\n");
  
  fdtable_foreach(i)
    fd_print(fdtable[i]);
  
  buffer_flush(fd_out->w);
  return 0;
}


#include "../../lib/alloc.h"
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "../fd.h"
#include "../fdtable.h"
#include "../redir.h"
#include "../../lib/open.h"
#include "../../lib/shell.h"
#include "../../lib/str.h"
#include <stdlib.h>
#include "../../lib/windoze.h"
#if WINDOWS_NATIVE
#include <io.h>
#else
#include <unistd.h>
#endif

#include "../debug.h"

#ifndef PACKAGE_NAME
#define PACKAGE_NAME "shish"
#endif

#define FD_TEMPPFX "/tmp/" PACKAGE_NAME "-"
#define FD_TEMPLEN (sizeof(FD_TEMPPFX) + 6)

char fd_tempname[FD_TEMPLEN] = FD_TEMPPFX;

/* opens a temporary file and adds it as the specified virtual fd
 * ----------------------------------------------------------------------- */
int
fd_tempfile(struct fd* fd) {
  int e;

  /* reset the template to what mkstemp expects */
  str_copy(&fd_tempname[sizeof(fd_tempname) - 7], "XXXXXX");

  /* try to create a tempfile and exit on failure
     otherwise track the newly created file descriptor */
  if((e = mkstemp(fd_tempname)) == -1)
    return e;

  fdtable_track(e, FDTABLE_LAZY);

  /* tempfiles are initially in write mode only */
  fd->mode = FD_WRITE;

  fd_setfd(fd, e);

  /* unlink the file, the fd should now be the only reference */
  unlink(fd_tempname);

  /* make a copy of the name because the
     next call will change fd_tempname */
  fd->name = str_dup(fd_tempname);
  fd->mode |= FD_FREENAME;

  return e;
}

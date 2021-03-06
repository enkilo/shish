/* this header file comes from libowfat, http://www.fefe.de/libowfat/ */
#ifndef OPEN_H
#define OPEN_H

#include "typedefs.h"
#include "windoze.h"
#include "uint64.h"

/* open filename for reading and return the file handle or -1 on error */
int open_read(const char* filename);

/* create filename for exclusive write only use (mode 0600) and return
 * the file handle or -1 on error */
int open_excl(const char* filename);

/* open filename for appending  write only use (mode 0600)
 * and return the file handle or -1 on error.
 * All write operation will append after the last byte, regardless of
 * seeking or other processes also appending to the file.  The file will
 * be created if it does not exist. */
int open_append(const char* filename);

/* open filename for writing (mode 0644).  Create the file if it does
 * not exist, truncate it to zero length otherwise.  Return the file
 * handle or -1 on error. */
int open_trunc(const char* filename);

#ifdef STRALLOC_H
int openreadclose(const char* fn, stralloc* sa, size_t bufsize);
ssize_t readclose_append(int64 fd, stralloc* sa, size_t bufsize);
ssize_t readclose(int64 fd, stralloc* sa, size_t bufsize);
#endif

int open_temp(char** tmpl);

#endif

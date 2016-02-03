#include <sys/types.h>
#include <sys/stat.h>
<<<<<<< HEAD
#ifndef WIN32
#include <unistd.h>
#endif
#ifdef WIN32
=======
#ifdef _WIN32
>>>>>>> 6c7455723b47a4989fb5bb621be8f200a306f361
#include <windows.h>
#else
#include <unistd.h>
#include <sys/mman.h>
#endif
#include "open.h"
#include "mmap.h"

char mmap_empty[] = { 0 };

char* mmap_read_fd(int fd, unsigned long *filesize)
{
<<<<<<< HEAD
#ifdef WIN32
=======
#ifdef _WIN32
>>>>>>> 6c7455723b47a4989fb5bb621be8f200a306f361
  HANDLE m;
  char* map;
  m=CreateFileMapping((HANDLE)fd,0,PAGE_READONLY,0,0,NULL);
  map=0;
  if (m)
    map=MapViewOfFile(m,FILE_MAP_READ,0,0,0);
  CloseHandle(m);
  return map;
#else
  struct stat st;
  char *map = mmap_empty;
  if(fstat(fd, &st) == 0 && (*filesize = st.st_size))
  {
    map=mmap(0,*filesize,PROT_READ,MAP_SHARED,fd,0);
    if (map==(char*)-1)
      map=0;
  }
  return map;
#endif
}

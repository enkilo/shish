/* ported from dietlibcs mkstemp() */

<<<<<<< HEAD
#ifdef WIN32
=======
#ifdef _WIN32
>>>>>>> 6c7455723b47a4989fb5bb621be8f200a306f361
#include <io.h>
#else
#include <unistd.h>
#endif
#include <fcntl.h>
#include <errno.h>
#include "str.h"
#include "open.h"
#include "str.h"
#include "uint32.h"

#ifndef O_NOFOLLOW
#define O_NOFOLLOW 0
#endif

int open_temp(char *tmpl) 
{  
  char *tmp=tmpl+str_len(tmpl)-6;
  int i,res;
  unsigned int random;
  if(tmp<tmpl) goto error;
  for(i=0; i<6; ++i) if (tmp[i]!='X')
  {
    error: errno=EINVAL; return -1; 
  }
  for(;;)
  {
    random = uint32_random();
    for (i=0; i<6; ++i)
    {
      int hexdigit=(random>>(i*5))&0x1f;
      tmp[i]=hexdigit>9?hexdigit+'a'-10:hexdigit+'0';
    }
    
    res=open(tmpl,O_CREAT|O_RDWR|O_EXCL|O_NOFOLLOW,0600);
    if(res>=0 || errno!=EEXIST) break;
  }
  return res;
}

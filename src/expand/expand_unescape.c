#include "../parse.h"
#include "../../lib/stralloc.h"
#include "../tree.h"

/* in-place unescape
 * ----------------------------------------------------------------------- */
void
expand_unescape(stralloc* sa, int(pred)(int)) {
  unsigned int s, d;

  for(s = d = 0; s < sa->len; s++) {
    /* skip backslash */
    if(sa->s[s] == '\\' && pred(sa->s[s + 1]))
      s++;

    /* damn, string shouldn't end here */
    if(s == sa->len)
      break;

    /* move only if we already unescaped something */
    if(s != d)
      sa->s[d] = sa->s[s];

    d++;
  }

  sa->len = d;
  stralloc_nul(sa);
}

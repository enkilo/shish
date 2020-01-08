#include "expand.h"
#include "tree.h"

/* expand all arguments of an argument list
 * returns count of argument nodes
 * ----------------------------------------------------------------------- */
int
expand_args(union node* args, union node** nptr) {
  union node* arg;
  union node* n;
  int ret = 0;

  *nptr = NULL;

  for(arg = args; arg; arg = arg->list.next) {

    if((n = expand_arg(&arg->narg, nptr))) {
      nptr = &n;
      ret++;
    }

    if(n == NULL)
      continue;

    if(n->narg.flag & X_GLOB) {
      if((n = expand_glob(nptr, n->narg.flag & ~X_GLOB))) {
        nptr = &n;
        ret++;
      }
    } else {
      expand_unescape(&n->narg.stra);
      n->narg.flag &= ~X_GLOB;
    }

    if(arg->list.next) {
      n->list.next = tree_newnode(N_ARG);
      nptr = &n->list.next;
      n = *nptr;
      stralloc_init(&n->narg.stra);
      ret++;
    }
  }

  return ret;
}

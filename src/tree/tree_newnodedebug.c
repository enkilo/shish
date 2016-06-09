#include "shell.h"
#include "byte.h"
#include "tree.h"

/* allocate a tree node
 * ----------------------------------------------------------------------- */
union node *tree_newnodedebug(const char *file, unsigned int line, enum nod_id nod) {
  union node *ret;

  if((ret = shell_allocdebug(file, line, sizeof(union node)))) {
    byte_zero(ret, sizeof(union node));
    ret->id = nod;
  }
  return ret;
}
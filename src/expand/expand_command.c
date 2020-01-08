#include "eval.h"
#include "expand.h"
#include "fd.h"
#include "fdstack.h"
#include "sh.h"
#include "tree.h"
#include "var.h"
#include <unistd.h>

/* evaluates backquoted command list, while writing stdout to a stralloc
 * ----------------------------------------------------------------------- */
union node*
expand_command(struct expand* ex, struct nargcmd* cmd) {
  union node* n = ex->ptr;
  struct vartab vars;
  struct fd fd;
  struct fdstack fdst;
  struct env sh;
  stralloc sa;
  stralloc_init(&sa);

  /* do this in a new i/o context so we can redirect stdout */
  vartab_push(&vars);

  /* make the output buffer write to the stralloc */
  fdstack_push(&fdst);
  fd_push(&fd, STDOUT_FILENO, FD_WRITE);
  fd_subst(&fd, &sa);

  /* evaluate the command tree in a subshell */
  sh_push(&sh);
  sh_subshell(cmd->list, E_EXIT);
  sh_pop(&sh);

  fdstack_pop(&fdst);

  vartab_pop(&vars);

  /* split trailing newlines */
  while(sa.len && sa.s[sa.len - 1] == '\n') sa.len--;

  /* expand the output of the command

     FIXME: we could do this much nicer by doing an
            expand_write() which is set as buffer op
            on the output fd.

            so we won't have to alloc all the stuff twice!
   */
  n = expand_cat(&ex, sa.s, sa.len);
  stralloc_free(&sa);

  return n;
}

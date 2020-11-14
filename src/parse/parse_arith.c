#include "../debug.h"
#include "../fd.h"
#include "../parse.h"
#include "../source.h"
#include "../tree.h"

/* parse arithmetic expression
 * ----------------------------------------------------------------------- */
int
parse_arith(struct parser* p) {
  union node* tree;
  struct parser subp;

  parse_skip(p);

  parse_init(&subp, P_ARITH | P_NOREDIR);

  tree = parse_arith_expr(&subp);

  if(tree) {
#ifdef DEBUG_OUTPUT_
    debug_node(tree, 0);
#endif

    buffer_flush(fd_err->w);

    /* MUST be terminated with 2 right parentheses */
    if(!parse_expect(&subp, P_DEFAULT, T_RP, tree) || !parse_expect(&subp, P_DEFAULT, T_RP, tree))
      return -1;

    parse_newnode(p, N_ARGARITH);
    p->node->nargarith.tree = tree;

    return 0;
  }
  return -1;
}

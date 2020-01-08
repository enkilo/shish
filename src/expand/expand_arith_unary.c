#include "expand.h"
#include "tree.h"
#include "uint64.h"
#include <math.h>

/* expand a unary expression
 * ----------------------------------------------------------------------- */
int
expand_arith_unary(struct expand* ex, struct narithunary* expr, int64* r) {
  int64 value;

  if(expand_arith_expr(ex, expr->node, &value))
    return 1;

  switch(expr->id) {
    case A_UNARYMINUS: *r = 0 - value; break;
    case A_UNARYPLUS: *r = value; break;
    case A_NOT: *r = !value; break;
    case A_BNOT: *r = ~value; break;

    default: __asm__("int $3"); break;
  }

  return 0;
}

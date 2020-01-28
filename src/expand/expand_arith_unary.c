#include "expand.h"
#include "tree.h"
#include "uint64.h"
#include <math.h>

/* expand a unary expression
 * ----------------------------------------------------------------------- */
int
expand_arith_unary(struct narithunary* expr, int64* r) {
  int64 value;
  struct nargparam* param = 0;
  struct var* v = 0;
  int pre_post = expr->id == A_PREINCREMENT || expr->id == A_PREDECREMENT || expr->id == A_POSTINCREMENT ||
                 expr->id == A_POSTDECREMENT;

  if(expand_arith_expr(expr->node, &value))
    return 1;

  if(pre_post) {
    param = &expr->node->nargparam;

    v = var_search(param->name, NULL);
  }

  switch(expr->id) {
    case A_UNARYMINUS: *r = 0 - value; break;
    case A_UNARYPLUS: *r = value; break;
    case A_PREINCREMENT: *r = ++value; break;
    case A_POSTINCREMENT: *r = value++; break;
    case A_PREDECREMENT: *r = --value; break;
    case A_POSTDECREMENT: *r = value--; break;
    case A_NOT: *r = !value; break;
    case A_BNOT: *r = ~value; break;

    default: __asm__("int $3"); break;
  }

  if(pre_post) {
    if(param && param->name)
      var_setvint(param->name, value, 0);
  }

  return 0;
}

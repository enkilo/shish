#include "../expand.h"
#include "../tree.h"
#include "../var.h"
#include "../../lib/uint64.h"
#include "../../lib/scan.h"

/* expand a assignment expression
 * ----------------------------------------------------------------------- */
int
expand_arith_assign(struct narithbinary* assign, int64* r) {

  if(assign->left->id == N_ARGPARAM) {
    int64 left = 0, right = 0;
    size_t offset;
    const char* s;
    struct var* v;
    struct nargparam* param = &assign->left->nargparam;

    if((s = var_vdefault(param->name,"0", 0)) == 0 || !scan_longlong(s, &left))
      left = 0;

    if(expand_arith_expr(assign->right, &right))
      right = 0;

    switch(assign->id) {
      case A_ASSIGN: left = right; break;
      case A_ASSIGNADD: left += right; break;
      case A_ASSIGNSUB: left -= right; break;
      case A_ASSIGNMUL: left *= right; break;
      case A_ASSIGNDIV: left /= right; break;
      case A_ASSIGNMOD: left %= right; break;
      case A_ASSIGNLSHIFT: left <<= right; break;
      case A_ASSIGNRSHIFT: left >>= right; break;
      case A_ASSIGNBAND: left &= right; break;
      case A_ASSIGNBXOR: left ^= right; break;
      case A_ASSIGNBOR: left |= right; break;
      default: return 1;
    }

    {
      char buf[FMT_LONG * 2];
      var_setv(param->name, buf, fmt_longlong(buf, left), V_DEFAULT);
    }

    *r = left;
  }
  return 0;
}

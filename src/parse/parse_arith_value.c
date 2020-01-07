#include "fmt.h"
#include "parse.h"
#include "scan.h"
#include "source.h"
#include "tree.h"
#include "uint64.h"

/* parse arithmetic value
 * ----------------------------------------------------------------------- */
union node*
parse_arith_value(struct parser* p) {
  char c;
  union node* node = NULL;

  if(source_peek(&c) <= 0)
    return NULL;

  if(c == '(')
    return parse_arith_paren(p);

  if(parse_isdigit(c)) {
    char x[FMT_LONG + 1];
    unsigned int n = 0;
    int64 num;

    do {
      x[n++] = c;

      if(source_next(&c) <= 0)
        break;

    } while(parse_isdigit(c) && n < FMT_LONG);

    x[n] = '\0';

    scan_longlong(x, &num);

    node = tree_newnode(N_ARITH_NUM);
    node->narithnum.num = num;

    return node;
  }

  return NULL;

  /*
  union node* node = 0;
  char x[FMT_LONG+1];
  long long num;
  unsigned int n;

  if(source_peekn(x,FMT_LONG) <= 0)
    return 0;

  if((n = scan_longlong(x, &num)) > 0) {
    node = tree_newnode(N_ARITH_NUM);
    node->narithnum.num = num;
    while(n--)
        source_skip();
  } else {
    char c;
    stralloc w;
    stralloc_init(&w);

    while(source_peek(&c) > 0 && !parse_isspace(c)) {
        stralloc_catc(&w, c);
        source_skip();
    }
    stralloc_catc(&w, '\0');

    node = tree_newnode(N_ARITH_VAR);
    node->narithvar.var = w.s	;
  }

  return node;*/
}

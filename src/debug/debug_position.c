#define DEBUG_NOCOLOR 1
#include "../debug.h"
#include "../tree.h"

/* ----------------------------------------------------------------------- */
void
debug_position(const char* msg, const struct position* pos, int depth) {
  if(msg)
    debug_field(msg, depth);
  debug_s("{");

  debug_ulong("line", pos->line, -1);
  debug_ulong(", column", pos->column, -1);

  debug_newline(-1);
  debug_s("}");
  debug_fl();
}

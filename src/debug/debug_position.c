
#define DEBUG_NOCOLOR 1
#include "../debug.h"
#include "../tree.h"
#include "../source.h"

#if defined(DEBUG_OUTPUT) || defined(SHPARSE2AST)

/* ----------------------------------------------------------------------- */
void
debug_position(const char* msg, const struct location* pos, int depth) {
  if(msg)
    debug_field(msg, depth);
  debug_s("{");

  debug_ulong("line", pos->line, -1);
  debug_ulong(", col", pos->column, -1);
  debug_ulong(", offset", pos->offset, -1);

  debug_newline(-1);
  debug_s("}");
  debug_fl();
}

void
debug_location(const char* msg, const struct location* pos, int depth) {
  char buf[FMT_LOC];

  buf[fmt_location(buf, *pos)] = '\0';
  debug_str(msg, buf, depth, '"');
  debug_fl();
}
#endif

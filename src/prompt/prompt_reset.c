#include "../prompt.h"
#include "../debug.h"

void
prompt_reset(void) {
  prompt_number = 0;
#ifdef DEBUG_OUTPUT
  debug_fn();
  #endif
}

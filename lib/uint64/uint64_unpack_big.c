#include "uint64.h"
#include "../uint64.h"
#undef NO_UINT64_MACROS
#include "../uint32.h"

void
uint64_unpack_big(const char* in, uint64* out) {
  *out = uint64_read_big(in);
}

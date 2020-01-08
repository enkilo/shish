#include "parse.h"
#include "tree.h"

/* character class table
 * ----------------------------------------------------------------------- */
const unsigned short parse_chartable[CHAR_RANGE] = {
    /* 0x00 */
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_SPACE,
    C_SPACE,
    C_UNDEF,
    C_UNDEF,
    C_SPACE,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    /* 0x20 */
    C_SPACE,
    C_SPCL,
    C_DESC | C_QUOT,
    C_SPCL,
    C_SPCL | C_DESC,
    C_UNDEF,
    C_UNDEF,
    C_QUOT,
    C_CTRL,
    C_CTRL,
    C_SPCL | C_ESC,
    C_UNDEF,
    C_UNDEF,
    C_SPCL,
    C_UNDEF,
    C_UNDEF,
    C_DIGIT,
    C_HEX,
    C_OCTAL,
    C_BINARY,
    C_DIGIT,
    C_HEX,
    C_OCTAL,
    C_BINARY,
    C_DIGIT,
    C_HEX,
    C_OCTAL,
    C_DIGIT,
    C_HEX,
    C_OCTAL,
    C_DIGIT,
    C_HEX,
    C_OCTAL,
    C_DIGIT,
    C_HEX,
    C_OCTAL,
    C_DIGIT,
    C_HEX,
    C_OCTAL,
    C_DIGIT,
    C_HEX,
    C_OCTAL,
    C_DIGIT,
    C_HEX,
    C_DIGIT,
    C_HEX,
    C_UNDEF,
    C_CTRL,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_SPCL | C_ESC,
    /* 0x40 */
    C_SPCL,
    C_UPPER,
    C_HEX,
    C_UPPER,
    C_HEX,
    C_UPPER,
    C_HEX,
    C_UPPER,
    C_HEX,
    C_UPPER,
    C_HEX,
    C_UPPER,
    C_HEX,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_UPPER,
    C_ESC,
    C_ESC,
    C_ESC,
    C_UNDEF,
    C_NAME,
    /* 0x60 */
    C_DESC | C_QUOT,
    C_LOWER,
    C_HEX,
    C_LOWER,
    C_HEX,
    C_LOWER,
    C_HEX,
    C_LOWER,
    C_HEX,
    C_LOWER,
    C_HEX,
    C_LOWER,
    C_HEX,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_LOWER,
    C_UNDEF,
    C_CTRL,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    /* 0x80 */
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    /* 0xa0 */
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    /* 0xc0 */
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    /* 0xe0 */
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
    C_UNDEF,
};

const char* expr_tokens[] = {
    "\0",  /* X_EOF           */
    "+",   /* X_ADD           */
    "-",   /* X_SUB           */
    "*",   /* X_MUL           */
    "/",   /* X_DIV           */
    "%",   /* X_MOD           */
    "<<",  /* X_LSHIFT        */
    ">>",  /* X_RSHIFT        */
    "<",   /* X_LT            */
    ">",   /* X_GT            */
    "<=",  /* X_LE            */
    ">=",  /* X_GE            */
    "==",  /* X_EQUAL         */
    "!=",  /* X_NEQUAL        */
    "&",   /* X_BAND          */
    "^",   /* X_BXOR          */
    "|",   /* X_BOR           */
    "&&",  /* X_LAND          */
    "||",  /* X_LOR           */
    "?",   /* X_QUEST         */
    ":",   /* X_COLON         */
    "=",   /* X_ASSIGN        */
    "+=",  /* X_ADD_ASSIGN    */
    "-=",  /* X_SUB_ASSIGN    */
    "*=",  /* X_MUL_ASSIGN    */
    "/=",  /* X_DIV_ASSIGN    */
    "%=",  /* X_MOD_ASSIGN    */
    "<<=", /* X_LSHIFT_ASSIGN */
    ">>=", /* X_RSHIFT_ASSIGN */
    "&=",  /* X_BAND_ASSIGN   */
    "^=",  /* X_BXOR_ASSIGN   */
    "|=",  /* X_BOR_ASSIGN    */
    "++",  /* X_INC           */
    "--",  /* X_DEC           */
    "+",   /* X_UADD          */
    "-",   /* X_USUB          */
    "~",   /* X_BNOT          */
    "!",   /* X_LNOT          */
    "(",   /* X_LP            */
    ")",   /* X_RP            */
    ",",   /* X_COMMA    (44) */
};

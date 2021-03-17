#include "../tree.h"

const int tree_nodesizes[] = {
    sizeof(struct ncmd),         /* N_SIMPLECMD */
    sizeof(struct npipe),        /* N_PIPELINE */
    sizeof(struct nandor),       /* N_AND */
    sizeof(struct nandor),       /* N_OR */
    sizeof(struct nnot),         /* N_NOT */
    sizeof(struct ngrp),         /* N_SUBSHELL */
    sizeof(struct ngrp),         /* N_CMDLIST */
    sizeof(struct nfor),         /* N_FOR */
    sizeof(struct ncase),        /* N_CASE */
    sizeof(struct ncasenode),    /* N_CASENODE */
    sizeof(struct nif),          /* N_IF */
    sizeof(struct nloop),        /* N_WHILE */
    sizeof(struct nloop),        /* N_UNTIL */
    sizeof(struct nfunc),        /* N_FUNCTION */
    sizeof(struct narg),         /* N_ARG */
    sizeof(struct narg),         /* N_ASSIGN */
    sizeof(struct nredir),       /* N_REDIR */
    sizeof(struct nargstr),      /* N_ARGSTR */
    sizeof(struct nargcmd),      /* N_ARGCMD */
    sizeof(struct nargparam),    /* N_ARGPARAM */
    sizeof(struct nargarith),    /* N_ARGARITH */
    sizeof(struct narithnum),    /* A_NUM */
    sizeof(struct nargarith),    /* A_PAREN */
    sizeof(struct narithbinary), /* A_OR */
    sizeof(struct narithbinary), /* A_AND */
    sizeof(struct narithbinary), /* A_BOR */
    sizeof(struct narithbinary), /* A_BXOR */
    sizeof(struct narithbinary), /* A_BAND */
    sizeof(struct narithbinary), /* A_EQ */
    sizeof(struct narithbinary), /* A_NE */
    sizeof(struct narithbinary), /* A_LT */
    sizeof(struct narithbinary), /* A_GT */
    sizeof(struct narithbinary), /* A_GE */
    sizeof(struct narithbinary), /* A_LE */
    sizeof(struct narithbinary), /* A_LSHIFT */
    sizeof(struct narithbinary), /* A_RSHIFT */
    sizeof(struct narithbinary), /* A_ADD */
    sizeof(struct narithbinary), /* A_SUB */
    sizeof(struct narithbinary), /* A_MUL */
    sizeof(struct narithbinary), /* A_DIV */
    sizeof(struct narithbinary), /* A_MOD */
    sizeof(struct narithbinary), /* A_EXP */
    sizeof(struct narithunary),  /* A_UNARYMINUS */
    sizeof(struct narithunary),  /* A_UNARYPLUS */
    sizeof(struct narithunary),  /* A_NOT */
    sizeof(struct narithunary),  /* A_BNOT */
    sizeof(struct narithunary),  /* A_PREDECREMENT */
    sizeof(struct narithunary),  /* A_PREINCREMENT */
    sizeof(struct narithunary),  /* A_POSTDECREMENT */
    sizeof(struct narithunary)   /* A_POSTINCREMENT */
};

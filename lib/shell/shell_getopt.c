#include "../shell.h"
/* Based on dietlibc fnmatch (C) by Felix Leitner
 *
 * rewritten to support multiple runs
 */

#include "../str.h"

static const char default_prefixes[] = {'-',0};
struct optstate shell_opt = { default_prefixes };

int
shell_getopt(int argc, char* const argv[], const char* optstring) {
  if(shell_opt.ind == 0) {
    //shell_opt.ind = 1;
    shell_opt.ofs = 0;
    shell_opt.opt = '\0';
    shell_opt.arg = 0;
    shell_opt.prefixes = default_prefixes;
  }
  return shell_getopt_r(&shell_opt, argc, argv, optstring);
}

#define optind state->ind
#define optofs state->ofs
#define optopt state->opt
#define optarg state->arg
#define optprefix state->prefix
#define optprefixes state->prefixes

int
shell_getopt_r(struct optstate* state,
               int argc,
               char* const argv[],
               const char* optstring) {
  unsigned int offset;

  if(optind == 0) {
    if(optstring[0] == '+') {
    optprefixes = "+-";
    optstring++;
  } else {
    optprefixes = default_prefixes;
  }
  optind++;
  }

again:
  /* are we finished? */
  if(optind > argc || !argv[optind])
    return -1;

  offset = str_chr(optprefixes, argv[optind][0]);

  /* are we finished? */
  if(!(optprefix = optprefixes[offset]) || argv[optind][1] == 0)
    return -1;

  /* ignore a trailing - */
  if(argv[optind][1] == '-' && argv[optind][2] == '\0') {
    optind++;
    return -1;
  }

  /* if we're just starting then initialize local static vars */
  /*if(optidx != optind) {
    optidx = optind;
  }*(

  /* get next option char */
  optopt = argv[optind][optofs + 1];
  offset = str_chr(optstring, optopt);

  /* end of argument, continue on next one */
  if(optopt == '\0') {
    optind++;
    optofs = 0;
    goto again;
  }

  /* if the option char isn't in optstring we return '?' */
  if(optstring[offset] == '\0') {
    optind++;
    return '?';
  }

  /* argument expected? */
  if(optstring[offset + 1] == ':') {
    /* "-foo", return "oo" as optarg */
    if(optstring[offset + 2] == ':' || argv[optind][optofs + 2]) {
      if(!*(optarg = &argv[optind][optofs + 2]))
        optarg = 0;

      goto found;
    }

    optarg = argv[optind + 1];

    /* missing argument? */
    if(optarg == 0) {
      optind++;
      return ':';
    }

    optind++;
  }
  /* no argument */
  else {
    optofs++;
    return optopt;
  }

found:
  optind++;
  return optopt;
}

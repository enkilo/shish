# sigchld8-y.tst: yash-specific test of SIGCHLD handling (8)
../checkfg || skip="true" # %REQUIRETTY%

posix="true"

. ../signal.sh

signal_action_test_combo "$LINENO" -i -m ignored CHLD

# vim: set ft=sh ts=8 sts=4 sw=4 noet:

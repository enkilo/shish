# sigwinch7-y.tst: yash-specific test of SIGWINCH handling (7)
../checkfg || skip="true" # %REQUIRETTY%

posix="true"

. ../signal.sh

signal_action_test_combo "$LINENO" -i -m default WINCH

# vim: set ft=sh ts=8 sts=4 sw=4 noet:

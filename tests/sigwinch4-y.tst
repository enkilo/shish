# sigwinch4-y.tst: yash-specific test of SIGWINCH handling (4)
../checkfg || skip="true" # %REQUIRETTY%

posix="true"

. ../signal.sh

signal_action_test_combo "$LINENO" +i -m ignored WINCH

# vim: set ft=sh ts=8 sts=4 sw=4 noet:

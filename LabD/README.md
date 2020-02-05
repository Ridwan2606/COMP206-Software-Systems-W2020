.bash_profile : My account-specific login script. Your account login script could be a different one (.bashrc, .profile etc)

labd.c : The c programming section of the tutorial.

Also do note that comiling a C code using gcc sends data in two streams:

1.) stdout

2.) stderr

Errors detected in compiling is sent to the stderr (2).
Anything else is sent to the stdout (1).

By default both the stderr and stdout points to the screen/terminal.

To redirect the errors in compilation to a file arbitrarily called error.txt, do this command:

gcc labd.c 2>error.txt

The "2" is the stderr stream of the gcc command.

No error will be displayed on the screen for the compilation. You need to cat the
file error.txt to inspect the compilation errors.
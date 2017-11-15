Little Rooter
An Educational MACF / Root Kit Primer

Little Rooter is a small example of how MACF hooks can be used in place
of tampering with SYSENT in order to provide simple services to userland
from kernel space. In this example, any time the binary /private/tmp/.bash
is executed (regardless of what it is), the kernel changes the euid and
uid to 0 (root) for the process. Another MACF hook is also used to protect
the process from being deleted with rm or unlink()

Exercises for the student:

Easy:

1. While our secret .bash file cannot be deleted, it can be truncated by
   a call to open with O_TRUNC. Study xnu security/mac_policy.h to learn
   how to add a MACF hook to prevent this from happening.

2. Using security/mac_policy.h as a reference, use proc_selfname and a
   signal MACF hook to prevent any processes with the name -bash from
   being killed by a SIGINT or SIGKILL.

Advanced:

3. This kext is an I/O Kit driver and has been built to support a client
   connection from userland. Research I/O Kit and learn how to add
   support for an IOConnectCallMethod. Add a function that accepts a
   secret password as an argument and, if called with the correct password,
   will make the calling process root.

http://www.cs.dartmouth.edu/~sergey/cs108/guest_lectures/xnu-suggested-project.txt

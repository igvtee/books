/** @file
 * Lists implemented raw system calls on i386-freebsd.
 * @legal
 * Copyright &copy; 2004 Scott Lamb &lt;slamb@slamb.org&gt;.
 * This file is part of sigsafe, which is released under the MIT license.
 * @version     $Id: syscalls.h 718 2004-05-02 06:51:45Z slamb $
 * @author      Scott Lamb &lt;slamb@slamb.org&gt;
 */

SYSCALL(nanosleep, 2)
SYSCALL(read, 3)
SYSCALL(readv, 3)
SYSCALL(write, 3)
SYSCALL(writev, 3)
SYSCALL(select, 5)
SYSCALL(poll, 3)
SYSCALL(wait4, 4)
SYSCALL(accept, 3)
SYSCALL(connect, 3)

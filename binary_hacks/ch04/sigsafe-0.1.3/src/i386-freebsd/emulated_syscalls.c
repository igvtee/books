/** @file
 * Emulated system calls under i386-freebsd.
 * @legal
 * Copyright &copy; 2004 Scott Lamb &lt;slamb@slamb.org&gt;.
 * This file is part of sigsafe, which is released under the MIT license.
 * @version     $Id: emulated_syscalls.c 747 2004-05-09 00:03:40Z slamb $
 * @author      Scott Lamb &lt;slamb@slamb.org&gt;
 */

#include "sigsafe_internal.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

pid_t sigsafe_wait(int *status) {
    return sigsafe_wait4(WAIT_ANY, status, 0, NULL);
}

pid_t sigsafe_wait3(int *status, int options, struct rusage *rusage) {
    return sigsafe_wait4(WAIT_ANY, status, options, rusage);
}

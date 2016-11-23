/** @file
 * Emulated system calls on i386-linux.
 * @legal
 * Copyright &copy; 2004 Scott Lamb &lt;slamb@slamb.org&gt;.
 * This file is part of sigsafe, which is released under the MIT license.
 * @version     $Id: emulated_syscalls.c 747 2004-05-09 00:03:40Z slamb $
 * @author      Scott Lamb &lt;slamb@slamb.org&gt;
 */

#define _GNU_SOURCE
#include "sigsafe_internal.h"
#include <linux/net.h>

int sigsafe_socketcall(int call, unsigned long *args) PRIVATE;

int sigsafe_accept(int s, struct sockaddr *addr, socklen_t *addrlen) {
    unsigned long args[] = { s, (long) addr, (long) addrlen };
    return sigsafe_socketcall(SYS_ACCEPT, args);
}

int sigsafe_connect(int s, const struct sockaddr *name, socklen_t namelen) {
    unsigned long args[] = { s, (long) name, namelen };
    return sigsafe_socketcall(SYS_CONNECT, args);
}

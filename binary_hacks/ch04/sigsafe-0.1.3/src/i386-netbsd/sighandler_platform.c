/** @file
 * Adjusts instruction pointer as necessary on i386-netbsd.
 * @legal
 * Copyright &copy; 2004 Scott Lamb &lt;slamb@slamb.org&gt;.
 * This file is part of sigsafe, which is released under the MIT license.
 * @version     $Id: sighandler_platform.c 753 2004-05-11 08:12:25Z slamb $
 * @author      Scott Lamb &lt;slamb@slamb.org&gt;
 */

#include "sigsafe_internal.h"
#include <signal.h>
#include <unistd.h>

void sigsafe_handler_for_platform_(struct sigcontext *ctx) {
    struct sigsafe_syscall_ *s;
    void *eip;
    eip = (void*) ctx->sc_eip;
    for (s = sigsafe_syscalls_; s->minjmp != NULL; s++) {
        if (s->minjmp <= eip && eip <= s->maxjmp) {
#ifdef SIGSAFE_DEBUG_JUMP
            write(2, "[J]", 3);
#endif
            ctx->sc_eip = (long) s->jmpto;
            return;
        }
    }
}

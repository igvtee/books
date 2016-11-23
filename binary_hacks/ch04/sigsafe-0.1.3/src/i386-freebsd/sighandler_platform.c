/** @file
 * Adjusts instruction pointer as necessary on i386-freebsd.
 * @legal
 * Copyright &copy; 2004 Scott Lamb &lt;slamb@slamb.org&gt;.
 * This file is part of sigsafe, which is released under the MIT license.
 * @version     $Id: sighandler_platform.c 749 2004-05-09 04:08:17Z slamb $
 * @author      Scott Lamb &lt;slamb@slamb.org&gt;
 */

#include "sigsafe_internal.h"
#include <ucontext.h>
#include <unistd.h>

void sigsafe_handler_for_platform_(ucontext_t *ctx) {
    struct sigsafe_syscall_ *s;
    void *eip;
    eip = (void*) ctx->uc_mcontext.mc_eip;
    for (s = sigsafe_syscalls_; s->minjmp != NULL; s++) {
        if (s->minjmp <= eip && eip <= s->maxjmp) {
#ifdef SIGSAFE_DEBUG_JUMP
            write(2, "[J]", 3);
#endif
            ctx->uc_mcontext.mc_eip = (int) s->jmpto;
            return;
        }
    }
}

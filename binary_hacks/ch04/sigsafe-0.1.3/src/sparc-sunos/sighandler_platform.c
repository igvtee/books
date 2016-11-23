/** @file
 * Adjusts instruction pointer as necessary on sparc-sunos.
 * @legal
 * Copyright &copy; 2004 Scott Lamb &lt;slamb@slamb.org&gt;.
 * This file is part of sigsafe, which is released under the MIT license.
 * @version     $Id: sighandler_platform.c 752 2004-05-11 06:48:53Z slamb $
 * @author      Scott Lamb &lt;slamb@slamb.org&gt;
 */

#include "sigsafe_internal.h"
#include <ucontext.h>
#include <unistd.h>

void sigsafe_handler_for_platform_(ucontext_t *ctx) {
    struct sigsafe_syscall_ *s;
    void *pc;
    pc = (void*) ctx->uc_mcontext.gregs[REG_PC];
    for (s = sigsafe_syscalls_; s->minjmp != NULL; s++) {
        if (s->minjmp <= pc && pc <= s->maxjmp) {
#ifdef SIGSAFE_DEBUG_JUMP
            write(2, "[J]", 3);
#endif
            ctx->uc_mcontext.gregs[REG_PC ] = (long) s->jmpto;
            ctx->uc_mcontext.gregs[REG_nPC] = (long) s->jmpto + 4;
            return;
        }
    }
}

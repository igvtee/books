/** @file
 * Tests throughput speed of a pipe with variations of read(), to know how
 * sigsafe compares performance-wise to other methods of signal handling.
 * @legal
 * Copyright &copy 2004 &lt;slamb@slamb.org&gt;.
 * This file is part of sigsafe, which is released under the MIT license.
 * @version     $Id: bench_read.c 733 2004-05-06 03:28:41Z slamb $
 * @author      Scott Lamb &lt;slamb@slamb.org&gt;
 */

#include <limits.h>
#include <unistd.h>
#include <setjmp.h>
#include <assert.h>
#include <fcntl.h>

/*
 * FreeBSD's FD_ZERO uses bzero() but sys/select.h does not include string.h.
 * Workaround.
 */
#include <string.h>

#include <sys/select.h>
#ifdef DO_SAFE
#include <sigsafe.h>
#endif

#ifndef PIPE_BUF
/* OSF/1 doesn't */
#define PIPE_BUF _POSIX_PIPE_BUF
#endif

#define BYTES_TO_TRANSFER           4294967295uL
                            /* max: 4294967295uL */

#define min(a,b) ((a)<(b)?(a):(b))

#ifdef DO_SAFE
#define MYREAD sigsafe_read
#else
#define MYREAD read
#endif

int main(void) {
    int devzero;
    char buffer[PIPE_BUF];
#ifdef DO_SETJMP
    sigjmp_buf env;
#endif
    size_t total_transferred = 0;
#ifdef DO_SELECT
    int flags;
#endif

#ifdef DO_SAFE
    sigsafe_install_handler(SIGUSR1, NULL);
    sigsafe_install_tsd(0, NULL);
#endif

    devzero = open("/dev/zero", O_RDONLY);
#ifdef DO_SELECT
    /* Set to non-blocking */
    flags = fcntl(devzero, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(devzero, F_SETFL, flags);
#endif
    while (total_transferred < BYTES_TO_TRANSFER) {
        ssize_t retval;
#ifdef DO_SELECT
        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(devzero, &readset);
        retval = select(devzero+1, &readset, NULL, NULL, NULL);
        assert(retval == 1);
#endif
#ifdef DO_SETJMP
        sigsetjmp(env, 0);
#endif
        retval = MYREAD(devzero, buffer,
                min(PIPE_BUF, BYTES_TO_TRANSFER - total_transferred));
        assert(retval > 0);
        total_transferred += retval;
    }
    return 0;
}

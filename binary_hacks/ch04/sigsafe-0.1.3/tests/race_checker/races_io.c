/** @file
 * Tests for race conditions in IO-based functions.
 * @legal
 * Copyright &copy; 2004 Scott Lamb &lt;slamb@slamb.org&gt;.
 * This file is part of sigsafe, which is released under the MIT license.
 * @version         $Id: races_io.c 749 2004-05-09 04:08:17Z slamb $
 * @author          Scott Lamb &lt;slamb@slamb.org&gt;
 */

#include <sys/types.h>
#include <sys/select.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <sigsafe.h>
#include "race_checker.h"

enum pipe_half {
    READ = 0,
    WRITE
};

void* create_pipe(void) {
    void *test_data = NULL;

    test_data = malloc(sizeof(int)*2);
    assert(test_data != NULL);
    error_wrap(pipe((int*) test_data), "pipe", ERRNO);
    return test_data;
}

void cleanup_pipe(void *test_data) {
    int *mypipe = (int*) test_data;
    error_wrap(close(mypipe[READ]), "close", ERRNO);
    error_wrap(close(mypipe[WRITE]), "close", ERRNO);
    free(test_data);
}

#ifdef SIGSAFE_HAVE_SELECT
void do_sigsafe_select_read_child_setup(void *test_data) {
    int *mypipe = (int*) test_data;
    int flags;

    install_safe(test_data);

    flags = error_wrap(fcntl(mypipe[READ], F_GETFL), "fcntl", ERRNO);
    flags |= O_NONBLOCK;
    error_wrap(fcntl(mypipe[READ], F_SETFL, flags), "fcntl", ERRNO);
}
#endif

enum run_result do_sigsafe_read(void *test_data) {
    char c;
    int *mypipe = (int*) test_data;
    int retval;

    retval = sigsafe_read(mypipe[READ], &c, sizeof(char));
    if (retval == -EINTR) {
        return INTERRUPTED;
    } else if (retval == 1) {
        return NORMAL;
    } else {
        return WEIRD;
    }
}

#ifdef SIGSAFE_HAVE_SELECT
enum run_result do_sigsafe_select_read(void *test_data) {
    fd_set readset;
    char c;
    int *mypipe = (int*) test_data;
    int retval;

    FD_ZERO(&readset);
    FD_SET(mypipe[READ], &readset);
    retval = sigsafe_select(mypipe[READ]+1, &readset, NULL, NULL, NULL);
    if (retval == -EINTR) {
        return INTERRUPTED;
    } else if (retval != 1) {
        error_wrap(retval, "sigsafe_select", NEGATIVE);
        return WEIRD;
    }

    sigsafe_clear_received();

    retval = error_wrap(sigsafe_read(mypipe[READ], &c, sizeof(char)),
                        "sigsafe_read", NEGATIVE);
    if (retval == 1) {
        return NORMAL;
    }
    return WEIRD;
}
#endif

enum run_result do_racebefore_read(void *test_data) {
    char c;
    int *mypipe = (int*) test_data;
    int retval;

    if (signal_received) {
        return INTERRUPTED;
    }
    retval = read(mypipe[READ], &c, sizeof(char));
    if (retval == -1 && errno == EINTR) {
        return INTERRUPTED;
    } else if (retval == 1) {
        return NORMAL;
    } else {
        return WEIRD;
    }
}

enum run_result do_raceafter_read(void *test_data) {
    char c;
    int *mypipe = (int*) test_data;
    int retval;

    sigsetjmp(env, 1);
    jump_is_safe = 1;
    if (signal_received) {
        jump_is_safe = 0;
        return INTERRUPTED;
    }
    retval = read(mypipe[READ], &c, sizeof(char));
    jump_is_safe = 0;
    if (retval == 1) {
        return NORMAL;
    } else {
        return WEIRD;
    }
}

void nudge_read(void *test_data) {
    char c = 26;
    int *mypipe = (int*) test_data;
    int retval;
    retval = error_wrap(write(mypipe[WRITE], &c, sizeof(char)), "write", ERRNO);
    assert(retval == 1);
}

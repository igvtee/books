#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "sigsafe.h"

#define BUFFERSIZE 4096
volatile long counter = 0;

void handler(int signum, siginfo_t *si, ucontext_t *ctx, intptr_t user_data)
{
}

int main(int argc, char **argv)
{
	ssize_t ret;
	size_t wsize;
	char buf[BUFFERSIZE], *p;
	struct sigaction act;
	sigset_t defaultmask, intmask;

	sigemptyset(&intmask);
	sigaddset(&intmask, SIGINT);
	sigprocmask(SIG_SETMASK, &intmask, &defaultmask);

	sigsafe_install_handler(SIGINT, handler);
	sigsafe_install_tsd(0, NULL);

	counter = 0;
	for (;;) {
		sigprocmask(SIG_SETMASK, &defaultmask, NULL);
		ret = sigsafe_read(0, buf, BUFFERSIZE);
		sigprocmask(SIG_SETMASK, &intmask, &defaultmask);
		if (ret == -EINTR) {
			printf("%ld\n", counter);
			exit(0);
		}
		if (ret == 0)
			return 0;
		if (ret == -1) {
			perror("read");
			exit(1);
		}
		counter += ret;
		wsize = ret;
		p = buf;
		while (wsize) {
			ret = write(1, p, wsize);
			if (ret == -1) {
				perror("write");
				exit(1);
			}
			wsize -= ret;
			p += ret;
		}
	}
	return 0;
}

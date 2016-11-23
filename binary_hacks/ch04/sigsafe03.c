#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>

#define BUFFERSIZE 4096
volatile long counter = 0;
sigjmp_buf env;

void handler(int signum)
{
	siglongjmp(env, 1);
}

int main(int argc, char **argv)
{
	ssize_t ret;
	size_t wsize;
	char buf[BUFFERSIZE], *p;
	struct sigaction act;
	sigset_t defaultmask, intmask;

	if (sigsetjmp(env, 1) != 0) {
		printf("%ld\n", counter);
		exit(0);
	}

	sigemptyset(&intmask);
	sigaddset(&intmask, SIGINT);
	sigprocmask(SIG_SETMASK, &intmask, &defaultmask);

	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);

	counter = 0;
	for (;;) {
		sigprocmask(SIG_SETMASK, &defaultmask, NULL);
		/* 
		 * what to do if receive signal?
		 * ok.
		 */
		ret = read(0, buf, BUFFERSIZE);
		/*
		 * what to do if receive signal?
		 * fail. lost read data without write.
		 */
		sigprocmask(SIG_SETMASK, &intmask, &defaultmask);
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

#define _XOPEN_SOURCE 500
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stropts.h>

int iteration = 0;
char crlf[] = {0xd, 0xa, 0};

void handler(int s)
{
	/* read a character */
	int c = getchar();
	printf("got char %c, at count %d %s", c, iteration, crlf);

	if (c == 'q') {
		system("stty sane");
		exit(0);
	}
}

int main(void)
{
	/* set up the handler */
	sigset(SIGPOLL, handler);
	system("stty raw -echo");
	/* ask for interrupt driven input */
	ioctl(0, I_SETSIG, S_RDNORM);

	for (;;iteration++);
	/* can do other stuff here */

	return 0;
}

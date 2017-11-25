#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_fpe(int sig)
{
	printf("signal: %d\n", sig);
}

int main(void)
{
	float f = 1;

	if (signal(SIGFPE, sig_fpe) == SIG_ERR) {
		perror(NULL);
		exit(1);
	}
	f = f/0;
	printf("result: %f\n", f);

	return 0;
}

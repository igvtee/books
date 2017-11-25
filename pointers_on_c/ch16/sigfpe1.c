#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_fpe(int sig)
{
	printf("signal: %d\n", sig);
}

int main(void)
{
	int i = 1;

	if (signal(SIGFPE, sig_fpe) == SIG_ERR) {
		perror(NULL);
		exit(1);
	}
	i = i/0;
	printf("result: %d\n", i);

	return 0;
}

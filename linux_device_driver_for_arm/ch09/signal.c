#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigterm_handler(int signo)
{
	printf("Have caught sig N.O. %d\n", signo);
	exit(0);
}

int main(void)
{
	signal(SIGINT, sigterm_handler);
	signal(SIGTERM, sigterm_handler);
	while(1);
}

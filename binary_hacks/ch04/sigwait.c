#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *wait_for_sighup(void *dmy)
{
	int sig;

	sigset_t ss;
	sigemptyset(&ss);
	sigaddset(&ss, SIGHUP);

	while (1) {
		if (sigwait(&ss, &sig) == 0) {
			printf("Hello async-signal-safe world!\n");
		}
	}

	return NULL;
}

int main(void)
{
	sigset_t ss;
	pthread_t pt;

	pthread_attr_t atr;

	sigemptyset(&ss);
	sigaddset(&ss, SIGHUP);
	sigprocmask(SIG_BLOCK, &ss, NULL);

	pthread_attr_init(&atr);
	pthread_attr_setdetachstate(&atr, PTHREAD_CREATE_DETACHED);
	pthread_create(&pt, &atr, wait_for_sighup, NULL);

	sleep(10);

	return 0;
}

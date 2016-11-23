#include <signal.h>
#include <stddef.h>

static int sig = 0;
void handler(int signo)
{
	sig = 1;
}

int main(void)
{
	struct sigaction sa = {
		.sa_handler = handler,
		.sa_flags = 0,
	};

	sigemptyset(&sa.sa_mask);
	sigaction(SIGHUP, &sa, NULL);

	while (sig == 0);

	return 0;
}

#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/select.h>

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void unsafe_func(void)
{
	struct timeval tv = {20, 0};
	pthread_mutex_lock(&lock);
	select(0, NULL, NULL, NULL, &tv);	// sleep 20secs.
	pthread_mutex_unlock(&lock);
}

void handler(int signo)
{
	unsafe_func();
	_exit(1);
}

int main(void)
{
	struct sigaction sa = {
		.sa_handler = handler,
		.sa_flags = 0,
	};

	sigemptyset(&sa.sa_mask);
	sigaction(SIGHUP, &sa, NULL);

	unsafe_func();
	return 0;
}

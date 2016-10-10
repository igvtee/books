#include <stdio.h>
#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
		void *(*start_routine) (void *), void *arg)
	__attribute__((weak));

int main(void)
{
	if (pthread_create) {
		puts("This is multi-thread version");
	} else {
		puts("This is single-thread version");
	}
	return 0;
}

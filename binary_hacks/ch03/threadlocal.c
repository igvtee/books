#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 3

__thread int tls;
int global;

void * func(void *arg)
{
	int num = *(int *) arg;
	tls = num;
	global = num;
	sleep(1);
	printf("Thread=%d tls=%d global=%d\n", num, tls, global);
}

int main(void)
{
	int ret;
	pthread_t thread[THREADS];
	int num;

	for (num = 0; num < THREADS; num++) {
		ret = pthread_create(&thread[num], NULL, &func, (void *)&num);
		if (ret) {
			printf("error pthread_create\n");
			exit(1);
		}
	}

	for (num = 0; num < THREADS; num++) {
		ret = pthread_join(thread[num], NULL);
		if (ret) {
			printf("error pthread_join\n");
			exit(1);
		}
	}

	exit(0);
}

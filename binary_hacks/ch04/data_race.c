#include <pthread.h>

static int count = 1;
void * incr_count(void *p)
{
	++count;
	return 0;
}

static pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

void * lock_m1_then_m2(void *p)
{
	pthread_mutex_lock(&m1);
	pthread_mutex_lock(&m2);
	pthread_mutex_unlock(&m2);
	pthread_mutex_unlock(&m1);
	return 0;
}

void * lock_m2_then_m1(void *p)
{
	pthread_mutex_lock(&m2);
	pthread_mutex_lock(&m1);
	pthread_mutex_unlock(&m1);
	pthread_mutex_unlock(&m2);
	return 0;
}

int main(void)
{
	pthread_t t1, t2, t3, t4;

	pthread_create(&t1, NULL, incr_count, NULL);
	pthread_create(&t2, NULL, incr_count, NULL);
	pthread_create(&t3, NULL, lock_m1_then_m2, NULL);
	pthread_create(&t4, NULL, lock_m2_then_m1, NULL);
	pthread_join(t4, NULL);
	pthread_join(t3, NULL);
	pthread_join(t2, NULL);
	pthread_join(t1, NULL);
	return count;
}

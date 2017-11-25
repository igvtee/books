#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_RAND_NUM 10000

void rand_count(int *count, int mod)
{
	int i;

	for (i = 0; i < MAX_RAND_NUM; i++)
		count[i%mod]++;

	for (i = 0; i < mod; i++)
		printf("%02d: %05d\n", i, count[i]);
	putchar('\n');
}

int main(void)
{
	int count[10];
	int i;

	srand((unsigned int)time(NULL));
	for (i = 2; i <= 10; i++) {
		memset(count, 0, sizeof(count));
		rand_count(count, i);
	}

	return 0;
}

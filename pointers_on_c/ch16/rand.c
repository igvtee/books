#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	printf("rand() = %d, (0 - %d)\n", rand(), RAND_MAX);
	srand((unsigned int)time(NULL));
	printf("rand() = %d, with srand\n", rand());

	return 0;
}

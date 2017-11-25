#include <stdio.h>
#include <time.h>

int main(void)
{
	clock_t t;

	t = clock();
	if (t/CLOCKS_PER_SEC <= 1)
		printf("cpu usage time\n");
	else
		printf("total time\n");

	return 0;
}

#include <stdio.h>
#include <time.h>

int main(void)
{
	clock_t t;

	t = clock();
	if (t == (clock_t)-1) {
		printf("can't get clock\n");
		return 0;
	}

	printf("%ld %ld\n", t, CLOCKS_PER_SEC);
	t = clock();
	printf("%ld\n", t);

	return 0;
}

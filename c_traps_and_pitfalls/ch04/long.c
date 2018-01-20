#include <stdio.h>

long n = ~0;

extern void int_func(void);

int main(void)
{
	printf("main: %lx\n", n);
	int_func();
	printf("main: %lx\n", n);

	return 0;
}

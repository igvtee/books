#include <stdio.h>

extern double sqrt(double x) __attribute__((weak));

void func(void)
{
	if (sqrt)
		printf("%f\n", sqrt(10.0));
	else
		printf("sqrt isn't available\n");
}

#include <stdio.h>

extern int n;

void int_func(void)
{
	printf("int_func: %d\n", n);
	n = 0;
}

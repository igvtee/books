#include <stdio.h>

int main(void)
{
	int max = 4;
	const char *s = "hello, world";

	printf(":%.*s:\n", max, s);	// :hell:

	printf(":%s:\n", s);		// :hello, world:
	printf(":%10s:\n", s);		// :hello, world:
	printf(":%.10s:\n", s);		// :hello, wor:
	printf(":%-10s:\n", s);		// :hello, world:
	printf(":%.15s:\n", s);		// :hello, world:
	printf(":%-15s:\n", s);		// :hello, world   :
	printf(":%15.10s:\n", s);	// :     hello, wor:
	printf(":%-15.10s:\n", s);	// :hello, wor     :

	return 0;
}

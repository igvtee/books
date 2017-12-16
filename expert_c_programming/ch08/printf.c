#include <stdio.h>

int main(void)
{
	void *f = (void *)printf;

	(*(int (*)(const char *, ...))f)("Bite my shorts. Also my chars and ints\n");

	return 0;
}

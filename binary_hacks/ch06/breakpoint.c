#include <stdio.h>
#include <signal.h>

int main(void)
{
	printf("hello 1\n");

	raise(SIGTRAP);
	printf("hello 2\n");

	__asm__ __volatile__("int3");
	printf("hello 3\n");
	return 0;
}

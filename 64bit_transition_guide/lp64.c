#include <stdio.h>

int main(void)
{
#ifdef __LP64__
	/* 64-bit code */
	printf("64-bit code\n");
#else
	/* 32-bit code */
	printf("32-bit code\n");
#endif
	return 0;
}

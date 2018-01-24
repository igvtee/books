#include <stdio.h>

int main(void)
{
#ifdef __ppc__

	// 32-bit PowerPC code
	printf("32-bit PowerPC code\n");

#else

#ifdef __ppc64__

	// 64-bit PowerPC code
	printf("64-bit PowerPC code\n");

#else

#if defined(__i386__) || defined(__x86_64__)

	// 32-bit or 64-bit Intel code
	printf("32/64-bit Intel code\n");

#else

#error UNKNOWN ARCHITECTURE

#endif

#endif

#endif

	return 0;
}

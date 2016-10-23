#include <stdio.h>

__attribute__((cdecl))
foo(int a, int b)
{
	printf("a=%d, b=%d\n", a, b);
}

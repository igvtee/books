#include <stdio.h>
#include <limits.h>

int main(void)
{
	char a;

	printf("%d %d\n", CHAR_MIN, CHAR_MAX);
	a = '\x74';
	printf("%08x %d\n", a, a);
	a = '\x84';
	printf("%08x %d\n", a, a);

	return 0;
}

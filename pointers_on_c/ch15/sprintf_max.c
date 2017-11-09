#include <stdio.h>
#include <limits.h>

int main(void)
{
	char buf[128];
	int len;
	int a = INT_MAX;
	char b = 'a';
	unsigned int c = UINT_MAX;

	len = sprintf(buf, "%d %c %x", a, b, c);
	printf("buf: %s\nlength: %d\n", buf, len);

	return 0;
}

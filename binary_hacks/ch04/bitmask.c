#include <stdio.h>

int main(void)
{
	unsigned long n = 0;
	unsigned char *str;
	unsigned char data = 0xff;

	str = &data;
	n |= (*str & 0xff) << 24;
	printf("0x%0lx\n", n);

	return 0;
}

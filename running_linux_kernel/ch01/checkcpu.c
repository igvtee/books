#include <stdio.h>

int checkCPU(void)
{
	union w {
		int a;
		char b;
	} c;
	c.a = 1;

	return (c.b == 1);
}

int main(void)
{
	if (checkCPU())
		printf("little endian\n");
	else
		printf("big endian\n");
}

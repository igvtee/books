#include "syscalls.h"
#undef getchar

/* getchar: unbuffered single character input */
int getchar(void)
{
	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int main(void)
{
	int c;

	c = getchar();
	if (c == EOF)
		return -1;

	return 0;
}

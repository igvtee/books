#include "syscalls.h"
#undef getchar

/* getchar: simple buffered version */
int getchar(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0) {	/* buffer is empty */
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}

	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int main(void)
{
	int c;

	c = getchar();
	if (c == EOF)
		return -1;

	return 0;
}

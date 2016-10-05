#include <stdio.h>

int main(int argc, char **argv)
{
	char buf[8];
	if (argc >= 2) {
		char * s = argv[1], *d = buf;
		while (*s != '\0')
			*d++ = *s++;
	}
	return 0;
}

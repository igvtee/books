#include <stdio.h>

char *hello(char *arg)
{
	static char buf[4096];

	snprintf(buf, sizeof(buf), "hello, %s", arg);
	return buf;
}

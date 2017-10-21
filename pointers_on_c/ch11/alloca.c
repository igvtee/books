#include <stdio.h>
#include <alloca.h>
#include <string.h>

int main(void)
{
	char *buf = alloca(128);

	strcpy(buf, "Hello world.");
	printf("%s\n", buf);

	return 0;
}

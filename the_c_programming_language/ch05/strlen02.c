#include <stdio.h>

/* strlen: return length of string s */
size_t mystrlen(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
}

int main(void)
{
	char data[] = "Hello World!";

	printf("%s %ld\n", data, mystrlen(data));

	return 0;
}

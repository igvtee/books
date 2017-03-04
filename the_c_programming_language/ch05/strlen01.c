#include <stdio.h>

/* strlen: return length of string s */
int mystrlen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}

int main(void)
{
	char data[] = "Hello World!";

	printf("%s %d\n", data, mystrlen(data));

	return 0;
}

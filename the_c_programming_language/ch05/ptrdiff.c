#include<stdio.h>
#include<stddef.h>
#include<string.h>

int main(void)
{
	char str[] = "Hello world!";
	char *pstart = str;
	char *pend = str + strlen(str);

	ptrdiff_t difp = pend - pstart;
	printf("%td\n", difp);

	return 0;
}

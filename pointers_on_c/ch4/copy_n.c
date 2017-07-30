#include <stdio.h>

void copy_n(char dst[], char src[], int n)
{
	while (*src) {
		*dst++ = *src++;
		n--;
	}
	while (n) {
		*dst++ = '\0';
		n--;
	}
}

int main(void)
{
	char *src = "Hello world!";
	char dst[128];

	copy_n(dst, src, sizeof(dst));
	printf("%s\n", dst);

	return 0;
}

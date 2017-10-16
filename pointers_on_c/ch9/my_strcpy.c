#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	if (i == n)
		dest[n-1] = '\0';
	for ( ; i < n; i++)
		dest[i] = '\0';

	return dest;
}

int main(void)
{
	char str[] = "Hello world.";
	char buf[10];

	my_strcpy(buf, str, sizeof(buf));
	printf("%s %zu\n", buf, strlen(buf));

	return 0;
}

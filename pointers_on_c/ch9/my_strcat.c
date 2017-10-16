#include <stdio.h>
#include <string.h>

char * my_strcat(char *dest, const char *src, size_t n)
{
	size_t dest_len = strlen(dest);
	size_t i, j;

	/* no buffer left */
	if (dest_len >= n-1)
		return NULL;

	for (i = dest_len, j = 0; i < n && src[j] != '\0' ; i++, j++)
		dest[i] = src[j];
	if (i == n)
		dest[n-1] = '\0';

	return dest;
}


int main(void)
{
	char str[10] = "Hello ";

	my_strcat(str, "world.", sizeof(str));
	printf("%s\n", str);

	return 0;
}

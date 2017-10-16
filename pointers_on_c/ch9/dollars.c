#include <stdio.h>
#include <string.h>

void dollars(char *dest, char const *src)
{
	size_t len = strlen(src);

	*dest++ = '$';
	if (len == 0)
		strcpy(dest, "0.00");
	else if (len == 1)
		sprintf(dest, "0.0%c", *src);
	else if (len == 2)
		sprintf(dest, "0.%s", src);
	else
		while (len) {
			*dest++ = *src++;
			if (len == 3)
				*dest++ = '.';
			else if (len > 3 && (len % 3 == 0))
				*dest++ = ',';
			len--;
		}
}

int main(void)
{
	char dest[32];
	const char *src[] = {"", "1", "12", "123", "1234", "12345",
		"123456", "1234567", "12345678", "123456789", NULL
	};
	const char **psrc = src;

	while (*psrc != NULL) {
		dollars(dest, *psrc);
		printf("%-10s %s\n", *psrc, dest);
		psrc++;
	}

	return 0;
}

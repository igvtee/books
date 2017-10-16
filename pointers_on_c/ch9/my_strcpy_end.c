#include <stdio.h>
#include <string.h>

char *my_strcpy_end(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return dest;
}

int main(void)
{
	char str[] = "Hello";
	char buf[10];
	char *end;

	end = my_strcpy_end(buf, str);
	printf("%s %td\n", buf, end - buf);

	return 0;
}

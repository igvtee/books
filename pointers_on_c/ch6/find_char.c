#include <stdio.h>

/* strpbrk */
char const *find_char(char const *source, char const *chars)
{
	char const *ch;

	while (*source) {
		ch = chars;
		while (*ch) {
			if (*source == *ch)
				return source;
			ch++;
		}
		source++;
	}
	return NULL;
}

int main(void)
{
	char const *source = "ABCDEF";
	char const *chars1 = "XYZ";
	char const *chars2 = "XRCQEF";
	char const *ch;

	ch = find_char(source, chars1);
	if (ch)
		printf("find_char: %c\n", *ch);
	else
		printf("find_char: NULL\n");

	ch = find_char(source, chars2);
	if (ch)
		printf("find_char: %c\n", *ch);
	else
		printf("find_char: NULL\n");

	return 0;
}

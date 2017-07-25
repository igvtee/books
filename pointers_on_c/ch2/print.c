#include <stdio.h>

int main(void)
{
	char *data = "\"Blunder\?\?!\?\?\"";

	printf("%s\n", data);

	/* octal */
	printf("\\40: '%c'\n", '\40');
	printf("\\100: '%c'\n", '\100');
	/* hex */
	printf("\\x40: '%c'\n", '\x40');
	/* too big */
	printf("\\x100: '%c'\n", '\x100');
	/* '\012' '3' */
	printf("\\0123: '%c'\n", '\0123');
	/* too big */
	printf("\\x0123: '%c'\n", '\x0123');

	return 0;
}

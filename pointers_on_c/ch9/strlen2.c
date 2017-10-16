#include <stdio.h>
#include <string.h>

int main(void)
{
	char x[] = "this";
	char y[] = "example";

	/* correct example */
	if (strlen(x) >= strlen(y))
		printf("string x('%s') is large or equal " \
		       "than y('%s')\n", x, y);
	else
		printf("string x('%s') is less than " \
		       "y('%s')\n", x, y);

	/* wrong example */
	if (strlen(x) - strlen(y) >= 0)
		printf("string x('%s') is large or equal " \
		       "than y('%s')\n", x, y);
	else
		printf("string x('%s') is less than " \
		       "y('%s')\n", x, y);

	return 0;
}

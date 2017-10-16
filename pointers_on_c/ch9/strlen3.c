#include <stdio.h>
#include <string.h>

int main(void)
{
	char x[] = "this";

	/* correct example */
	if (strlen(x) >= 10)
		printf("string x('%s') is large or equal " \
		       "than 10\n", x);
	else
		printf("string x('%s') is less than 10\n", x);

	/* wrong example */
	if (strlen(x) - 10 >= 0)
		printf("string x('%s') is large or equal " \
		       "than 10\n", x);
	else
		printf("string x('%s') is less than 10\n", x);

	return 0;
}

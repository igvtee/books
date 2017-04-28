#include <stdio.h>
#include <ctype.h>

/* lower: convert input to lower case */
int main(void)
{
	int c;

	while ((c = getchar()) !=  EOF)
		putchar(tolower(c));
	return 0;
}

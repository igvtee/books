#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c;

	/* The terminal driver is in its ordinary line-at-a-time mode */
	system("stty raw");
	/* Now the terminal driver is in character-at-a-time mode */
	while ((c = getchar()) != EOF)
		putchar(c);
	system("stty cooked");
	/* The terminal driver is back in line-at-a-time mode */

	return 0;
}

#include <stdio.h>

/* replace string of blanks with a single blank */
main()
{
	int c, lastc;

	lastc = 1;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			if (lastc != ' ')
				putchar(c);
		if (c != ' ')
			putchar(c);
		lastc = c;
	}
}

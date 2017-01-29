#include <stdio.h>

/* count blanks, tabs and newlines */
main()
{
	int c, bl, ta, nl;

	bl = ta = nl = 0;
	while((c = getchar()) != EOF) {
		/* blank */
		if (c == ' ')
			++bl;
		/* tab */
		if (c == '\t')
			++ta;
		/* newline */
		if (c == '\n')
			++nl;
	}
	printf("blank: %d, tab: %d, newline: %d\n", bl, ta, nl);
}

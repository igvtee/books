#include <stdio.h>

#define MAX_LINE 5

int main(void)
{
	int lines = 1;
	int line_change = 0;
	int c;

	while (lines <= MAX_LINE) {
		if ((c = getchar()) == EOF)
			break;
		if (line_change == 0) {
			printf("%10d: ", lines);
			line_change = 1;
		}
		putchar(c);
		if (c == '\n') {
			lines++;
			line_change = 0;
		}
	}

	return 0;
}

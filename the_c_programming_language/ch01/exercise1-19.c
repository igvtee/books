#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int mygetline(char line[], int maxline);
void reverse(char line[], int i);

/* reverse line */
main()
{
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = mygetline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s", line);
	}

	return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char line[], int i)
{
	int j;
	char temp;

	--i;	/* back off from '\0' */
	if (line[i] == '\n')
		--i;	/* leave newline in place */
	j = 0;
	while (j < i) {
		temp = line[j];
		line[j] = line[i];	/* swap the characters */
		line[i] = temp;
		--i;
		++j;
	}
}

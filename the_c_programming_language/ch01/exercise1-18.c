#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int mygetline(char line[], int maxline);
int mytrim(char line[], int len);

/* remove trailing blanks and tabs. delete entirely blank lines */
main()
{
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = mygetline(line, MAXLINE)) > 0) {
		len = mytrim(line, len);
		if (len > 0)
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

int mytrim(char line[], int len)
{
	int newline;

	newline = 0;
	if (line[--len] == '\n') {
		newline = 1;
		--len;
	}

	while (len >= 0 && (line[len] == ' ' || line[len] == '\t'))
		--len;

	if (len >= 0) {
		if (newline)
			line[++len] = '\n';
		line[++len] = '\0';
	}

	return len;
}


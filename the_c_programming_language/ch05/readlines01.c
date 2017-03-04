#include <stdio.h>
#define MAXLEN 1000		/* max length of any input line */
int mygetline(char *, int);
char *alloc(int);
void strcpy_p3(char *s, char *t);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';	/* delete newline */
			strcpy_p3(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

#if 1
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
#else
	while (nlines--)
		printf("%s\n", *lineptr++);
#endif
}

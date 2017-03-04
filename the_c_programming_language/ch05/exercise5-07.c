#include <stdio.h>
#include <string.h>

#define MAXLEN	1000		/* max length of any input line */
#define MAXSTOR	5000		/* SIZE OF AVAILABLE STORAGE SPACE */

int mygetline(char *, int);
char *alloc(int);
void strcpy_p3(char *s, char *t);

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXSTOR;

	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || p+len > linestop)
			return -1;
		else {
			line[len-1] = '\0';	/* delete newline */
			strcpy_p3(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

#define MAXLINES 5000		/* max #lines to be sorted */

char *lineptr[MAXLINES];		/* pointers to text lines */

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(void)
{
	int nlines;		/* number of input lines read */
	char linestore[MAXSTOR];

	if ((nlines = readlines(lineptr, linestore, MAXLINES)) > 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

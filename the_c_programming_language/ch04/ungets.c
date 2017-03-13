#include <string.h>

void ungetch(int);

/* ungets: push string back onto the input */
void ungets(char s[])
{
	int len = strlen(s);

	while (len > 0)
		ungetch(s[--len]);
}

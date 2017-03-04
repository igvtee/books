#include <stdio.h>
#include <stdlib.h>

/* error: print error message and exit */
void error(char *s)
{
	printf("%s\n", s);
	exit(1);
}

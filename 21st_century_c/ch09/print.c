#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *s1 = "Thread";

	char *s2;
	asprintf(&s2, "Floss");

	printf("%s\n", s1);
	printf("%s\n", s2);

	s2[0] = 'f';	//switch Floss to lowercase.
	s1[0] = 't';	//segfault.

	free(s2);	//clean up.
	free(s1);	//segfault.
}

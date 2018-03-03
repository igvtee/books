#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_lines(char *instring)
{
	int counter = 0;
	char *scratch, *txt, *delimiter = "\n";

	while ((txt = strtok_r(!counter ? instring : NULL,
					delimiter, &scratch)))
		counter++;
	return counter;
}

int main()
{
	char *buf = malloc(128);
	int lines;

	/* two or more delimiters in a row are treated as a single
	 * delimiter, meaning that blank tokens are simply 
	 * ignored.
	 */
	strcat(buf, "1\n2\n3\n4\n\n\n\n5\n");
	lines = count_lines(buf);
	printf("lines %d\n", lines);

	free(buf);
}

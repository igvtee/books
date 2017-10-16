#include <stdio.h>
#include <string.h>

#define MAX_READ 100

int main(void)
{
	static char whitespace[] = " \t\f\r\v\n";
	char buf[MAX_READ];
	char *str;
	int cnt = 0;

	if (fgets(buf, MAX_READ, stdin) == NULL)
		goto error;

	for (str = strtok(buf, whitespace);
	     str != NULL;
	     str = strtok(NULL, whitespace)) {
		if (strcmp(str, "the") == 0)
			cnt++;
	}

	printf("total %d 'the' words\n", cnt);

error:
	return 0;
}

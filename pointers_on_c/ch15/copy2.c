#include <stdio.h>

#define MAX_LINE_SIZE 81

int main(void)
{
	char buf[MAX_LINE_SIZE];

	while (fgets(buf, MAX_LINE_SIZE, stdin)) {
		if (fputs(buf, stdout) < 0)
			break;
	}

	return 0;
}

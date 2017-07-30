#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 128

int main(void)
{
	int isprint = 0;
	char buf[MAX_LINE_SIZE];
	char rbuf[MAX_LINE_SIZE];

	buf[0] = '\0';
	while (fgets(rbuf, sizeof(rbuf), stdin) != NULL) {
		if (strcmp(buf, rbuf) == 0) {
			if (!isprint)
				printf("%s", buf);
			isprint = 1;
		} else {
			strncpy(buf, rbuf, sizeof(buf));
			isprint = 0;
		}
	}

	return 0;
}

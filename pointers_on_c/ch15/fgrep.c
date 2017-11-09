#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 512

void grep(const char *filename, const char *key, FILE *fp)
{
	char buf[MAX_LINE_SIZE];
	int nline = 0;

	while (fgets(buf, sizeof(buf), fp)) {
		if (strstr(buf, key)) {
			if (filename)
				printf("%s: %d: %s", filename, nline, buf);
			else
				printf("%d: %s", nline, buf);
		}
		nline++;
	}
}

int main(int argc, char **argv)
{
	int ret = -1;
	char **filename;
	FILE *fp;

	if (argc == 1) {
		printf("usage: %s <pattern> <file_list>\n", argv[0]);
		goto err;
	}

	filename = &argv[2];
	if (*filename == NULL) {
		/* use stdin as input */
		grep(NULL, argv[1], stdin);
	} else {
		while (*filename != NULL) {
			if ((fp = fopen(*filename, "r")) != NULL) {
				grep(*filename, argv[1], fp);
				fclose(fp);
			} else {
				perror("open file error: ");
				goto err;
			}

			filename++;
		}
	}

	ret = 0;
err:
	return ret;
}

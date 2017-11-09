#include <stdio.h>

#define MAX_LINE_SIZE 256

int main(int argc, char **argv)
{
	char buf[MAX_LINE_SIZE];
	FILE *in = NULL, *out = NULL;
	int ret = -1;

	if (argc != 3) {
		printf("usage: copy <in_file> <out_file>\n");
		goto err;
	}

	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	if (!in) {
		perror("open input file error: ");
		goto err;
	}
	if (!out) {
		perror("open output file error: ");
		goto err;
	}

	while (fgets(buf, MAX_LINE_SIZE, in)) {
		if (fputs(buf, out) < 0)
			break;
	}
	ret = 0;

err:
	if (in)
		fclose(in);
	if (out)
		fclose(out);
	return ret;
}

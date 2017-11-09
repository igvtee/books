#include <stdio.h>

#define MAX_LINE_SIZE 256

int main(int argc, char **argv)
{
	char buf[MAX_LINE_SIZE];
	FILE *in = NULL, *out = NULL;
	int ret = -1;
	int sum = 0, num;

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
		if (sscanf(buf, "%d", &num) == 1)
			sum += num;
		if (fputs(buf, out) < 0)
			break;
	}
	fprintf(out, "total num: %d\n", sum);
	ret = 0;

err:
	if (in)
		fclose(in);
	if (out)
		fclose(out);
	return ret;
}

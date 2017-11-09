#include <stdio.h>

int main(int argc, char **argv)
{
	int ret = -1;
	FILE *fp;
	char buf[128];
	int i, ages[10], sum, num;

	if (argc != 2) {
		printf("usage: %s <ages_file>\n", argv[0]);
		goto err;
	}

	fp = fopen(argv[1], "r");
	if (!fp) {
		perror("open ages file error: ");
		goto err;
	}

	while (fgets(buf, sizeof(buf), fp)) {
		sum = num = 0;
		num = sscanf(buf, "%d %d %d %d %d %d %d %d %d %d",
				&ages[0], &ages[1], &ages[2],
				&ages[3], &ages[4], &ages[5],
				&ages[6], &ages[7], &ages[8],
				&ages[9]);
		if (num <= 0)
			continue;

		for (i = 0; i < num; i++)
			sum += ages[i];
		printf("%5.2f: %s", (float)sum/num, buf);
	}

	fclose(fp);
err:
	return ret;
}

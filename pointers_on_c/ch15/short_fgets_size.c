#include <stdio.h>

int main(void)
{
	char buf1[1] = { 0xff };
	char buf2[2] = { 0xff, 0xff };
	char *ret;

	ret = fgets(buf1, sizeof(buf1), stdin);
	if (!ret)
		printf("fgets buf size 1 error\n");
	else
		printf("buf1: %02x\n", buf1[0]);

	ret = fgets(buf2, sizeof(buf2), stdin);
	if (!ret)
		printf("fgets buf size 2 error\n");
	else
		printf("buf2: %02x %02x\n", buf2[0], buf2[1]);

	return 0;
}

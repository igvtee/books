#include <stdio.h>
#include <ctype.h>

char *print_hex(char *buf, const char *data, int len)
{
	int i = 0;
	int num;

	while (i++ < len) {
		num = sprintf(buf, "%02hhX", *data++);
		buf += num;
		if (i % 4 == 0)
			*buf++ = ' ';
	}
	*buf = '\0';
}

char *print_value(char *buf, const char *data, int len)
{
	int i = 0;
	int num;

	while (i++ < len) {
		if (isprint(*data) == 0 || *data == ' ')
			*buf++ = '.';
		else
			*buf++ = *data;
		data++;
	}
	*buf = '\0';
}

int main(int argc, char **argv)
{
	int ret = -1;
	FILE *fp = stdin;
	int num, offset;
	char buf[16];
	char hexbuf[48];
	char valbuf[24];

	if (argc > 1) {
		fp = fopen(argv[1], "r");
		if (!fp) {
			perror("open file error: ");
			goto err;
		}
	}

	offset = 0;
	while ((num = fread(buf, 1, sizeof(buf), fp)) > 0) {
		print_hex(hexbuf, buf, num);
		print_value(valbuf, buf, num);
		printf("%06x  %-35.35s  *%-.16s*\n",
				offset, hexbuf, valbuf);
		offset += num;
	}

	if (fp != stdin)
		fclose(fp);
err:
	return ret;
}

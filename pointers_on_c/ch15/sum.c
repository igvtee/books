#include <stdio.h>
#include <unistd.h>

unsigned short checksum(FILE *fp)
{
	unsigned short sum = 0;
	int ch;

	while ((ch = fgetc(fp)) != EOF)
		sum += ch;

	return sum;
}

int main(int argc, char **argv)
{
	int ret = -1;
	int opt, cks_file = 0;
	int i;
	FILE *fp;
	unsigned short sum = 0;
	char cksname[128];

	while ((opt = getopt(argc, argv, "f")) != -1) {
		switch (opt) {
			case 'f':
				cks_file = 1;
				break;
			default:
				break;
		}
	}

	if (optind == argc) {
		/* use stdin */
		sum = checksum(stdin);
		printf("%hu\n", sum);
	} else {
		for (i = optind; i < argc; i++) {
			fp = fopen(argv[i], "r");
			if (!fp) {
				perror("open file error: ");
				goto err;
			}
			sum = checksum(fp);
			fclose(fp);
			if (cks_file) {
				snprintf(cksname, sizeof(cksname), "%s.cks", argv[i]);
				fp = fopen(cksname, "w");
				if (!fp) {
					perror("open file error: ");
					goto err;
				}
				fprintf(fp, "%hu\n", sum);
				fclose(fp);
			} else {
				printf("%hu\n", sum);
			}
		}
	}

	ret = 0;
err:
	return ret;
}

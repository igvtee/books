#include <stdio.h>
#define LENGTH 100

int main()
{
	FILE *fd;
	char str[LENGTH];

	fd = fopen("hello.txt", "w+");
	if (fd) {
		fputs("Hello World", fd);
		fclose(fd);
	}

	fd = fopen("hello.txt", "r");
	fgets(str, LENGTH, fd);
	printf("%s\n", str);
	fclose(fd);
}

#include <stdio.h>

#define NAMESIZE 14
char name[NAMESIZE];

int main(void)
{
	snprintf(name, sizeof(name), "hello");
	printf("====%.*s===\n", NAMESIZE, name);
	printf("====%*.*s===\n", NAMESIZE, NAMESIZE, name);
	printf("====%*.*s===\n", -NAMESIZE, NAMESIZE, name);

	return 0;
}

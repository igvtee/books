#include <stdio.h>

int main(int argc, char **argv)
{
	int a;
	printf("blah %n blah\n", &a);
	printf("a = %d\n", a);
	printf(argv[1]);
	return 0;
}

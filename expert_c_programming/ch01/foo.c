#include <stdlib.h>

void foo(const char **p)
{
}

void foo2(char ** const p)
{
}

int main(int argc, char **argv)
{
	foo(argv);
	foo2(argv);
	return 0;
}

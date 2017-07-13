#include <stdio.h>

int main(void)
{
	goto inner;
	{
		int foo = 3;
inner:
		printf("foo: %d\n", foo);
	}

	return 0;
}

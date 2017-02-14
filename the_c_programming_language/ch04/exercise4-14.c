#include <stdio.h>

#define swap(t, x, y)	{ t _z;	\
	_z =y;	\
	y = x;	\
	x = _z;	}

int main(void)
{
	int x = 3;
	int y = 4;

	swap(int, x, y);
	printf("x: %d, y: %d\n", x, y);

	return 0;
}

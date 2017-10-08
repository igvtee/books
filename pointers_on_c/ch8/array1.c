#include <stdio.h>

#define SHOW_DEFINE(x, y) printf(x, #y, y)

int main(void)
{
	int array[4][2] = {
		{0, 1},
		{10, 11},
		{20, 21},
		{30, 31},
	};

	SHOW_DEFINE("%-10s: %p\n", array);
	SHOW_DEFINE("%-10s: %p\n", array+2);
	SHOW_DEFINE("%-10s: %p\n", array[3]);
	SHOW_DEFINE("%-10s: %p\n", array[2]-1);
	SHOW_DEFINE("%-10s: %p\n", &array[1][2]);
	SHOW_DEFINE("%-10s: %p\n", &array[2][0]);

	return 0;
}

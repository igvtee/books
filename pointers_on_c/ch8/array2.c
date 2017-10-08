#include <stdio.h>

#define SHOW_DEFINE(x, y) printf(x, #y, y)

int main(void)
{
	int array[4][2][3][6] = {0};

	SHOW_DEFINE("%-20s: %p\n", array);
	SHOW_DEFINE("%-20s: %p\n", array+2);
	SHOW_DEFINE("%-20s: %p\n", array[3]);
	SHOW_DEFINE("%-20s: %p\n", array[2]-1);
	SHOW_DEFINE("%-20s: %p\n", array[2][1]);
	SHOW_DEFINE("%-20s: %p\n", array[1][0]+1);
	SHOW_DEFINE("%-20s: %p\n", array[1][0][2]);
	SHOW_DEFINE("%-20s: %p\n", array[0][1][0]+2);
	SHOW_DEFINE("%-20s: %d\n", array[3][1][2][5]);
	SHOW_DEFINE("%-20s: %p\n", &array[3][1][2][5]);

	return 0;
}

#include <stdio.h>

#define SHOW_DEFINE(y, x) printf(y, #x, x)

int iints[10] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};
int ints[20] = {
	10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
	110, 120, 130, 140, 150, 160, 170, 180, 190, 200
};
int intss[10] = {
	210, 220, 230, 240, 250, 260, 270, 280, 290, 300
};

int main(void)
{
	int *ip = ints + 3;

	SHOW_DEFINE("%-10s: %-20p", ints);
	SHOW_DEFINE("%-10s: %p\n", ip);
	SHOW_DEFINE("%-10s: %-20d", ints[4]);
	SHOW_DEFINE("%-10s: %d\n", ip[4]);
	SHOW_DEFINE("%-10s: %-20p", ints+4);
	SHOW_DEFINE("%-10s: %p\n", ip+4);
	SHOW_DEFINE("%-10s: %-20d", *ints+4);
	SHOW_DEFINE("%-10s: %d\n", *ip+4);
	SHOW_DEFINE("%-10s: %-20d", ints[-2]);
	SHOW_DEFINE("%-10s: %d\n", ip[-2]);
	SHOW_DEFINE("%-10s: %-20p", &ints);
	SHOW_DEFINE("%-10s: %p\n", &ip);
	SHOW_DEFINE("%-10s: %-20p", &ints[4]);
	SHOW_DEFINE("%-10s: %p\n", &ip[4]);
	SHOW_DEFINE("%-10s: %-20p", &ints+4);
	SHOW_DEFINE("%-10s: %p\n", &ip+4);
	SHOW_DEFINE("%-10s: %-20p", &ints[-2]);
	SHOW_DEFINE("%-10s: %p\n", &ip[-2]);

	return 0;
}

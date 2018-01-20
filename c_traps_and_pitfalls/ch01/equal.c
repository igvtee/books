#include <stdio.h>

int main(void)
{
	int x, y, filedesc;

	y = 1;
	do {
		/*
		 * if ((x = y) != 0)
		 */
		if (x = y) {
			printf("x = y\n");
			break;
		}
	} while (0);

	/*
	 * x = (' ' || c == '\t' || c == '\n')
	 * is always tree
	 * */
	while (x = ' ' || x == '\t' || x == '\n') {
		x = getc(stdin);
		break;
	}

	if ((filedesc == open("file", 0)) < 0)
		printf("error open\n");

	return 0;
}

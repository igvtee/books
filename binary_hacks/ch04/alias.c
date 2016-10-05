#include <stdio.h>

int main(int argc, char **argv)
{
	/* write as short(=16bit) */
	((short *)&argc)[0] |= 1;
	((short *)&argc)[1] |= 1;

	/* read as int(=32bit) */
	printf("%d\n", argc);

	return 0;
}

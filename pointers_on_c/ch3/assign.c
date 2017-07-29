#include <stdio.h>

int main(void)
{
	long ldata = -1;
	short sdata = ldata;

	printf("long:\t%lx\n", ldata);
	printf("short:\t%x\n", sdata);

	return 0;
}

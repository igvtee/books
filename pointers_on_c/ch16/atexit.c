#include <stdio.h>
#include <stdlib.h>

void myexit1(void)
{
	printf("%s\n", __func__);
}

void myexit2(void)
{
	printf("%s\n", __func__);
}


int main(void)
{
	atexit(myexit1);
	atexit(myexit2);
	exit(1);

	/* this can't happend */
	return 0;
}

#include <stdio.h>

int main(void)
{
	printf("__LINE__: %d\n" \
	       "__FILE__: %s\n" \
	       "__DATE__: %s\n" \
	       "__TIME__: %s\n" \
	       "__STDC__: %d\n",
	       __LINE__, __FILE__, __DATE__, __TIME__, __STDC__);
	return 0;
}

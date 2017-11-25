#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ret;
	ret = system(NULL);
	if (ret)
		printf("system works\n");
	else
		printf("system not works\n");

	return 0;
}

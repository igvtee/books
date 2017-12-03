#include <stdio.h>

int main(void)
{
	if ( -1 < (unsigned char)1)
		printf("-1 is less than (unsigned char)1: ANSI semantics\n");
	else
		printf("-1 is less than (unsigned char)1: K&R semantics\n");
	return 0;
}

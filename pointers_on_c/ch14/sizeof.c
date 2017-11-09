#include <stdio.h>

#if sizeof(int) == 2
typedef long int32;
#else
typedef int int32;
#endif

int main(void)
{
	int32 num = 0;

	return 0;
}

#include <stdio.h>

#define DEBUG_PRINT( fmt, expr ) \
	printf("File %s, line %d: %s = " \
			fmt "\n", \
			__FILE__, __LINE__, #expr, expr)

int main(void)
{
	int num = 10;

	DEBUG_PRINT("%s", "hello world");
	DEBUG_PRINT("%d", num);

	return 0;
}

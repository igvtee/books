#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "pragma_once.h"
#include "pragma_once.h"

int main(void)
{
	struct test t1;

	t1.i = 1;
	t1.j = 2;
	printf("%" PRId8 "\n", t1.i);
	printf("%" PRId16 "\n", t1.j);

	return 0;
}

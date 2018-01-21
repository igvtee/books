#include <stdint.h>

uint32_t loop(void)
{
	uint32_t sum;

	for (uint32_t i = 0; i < 10; i++)
		sum += i;

	return sum;
}

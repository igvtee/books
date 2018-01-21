#include <stdint.h>
#include <inttypes.h>

struct thing {
	uint64_t index;
	uint32_t counter;
};

int main(void)
{
	uint32_t numbers[64] = {0};
	struct thing localThing = {0};

	localThing.counter = numbers[1];

	return localThing.counter;
}

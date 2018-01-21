#include <stdint.h>
#include <inttypes.h>

struct thing {
	uint64_t index;
	uint32_t counter;
};

static const struct thing localThingNull = {0};

int main(void)
{
	struct thing localThing = {.counter = 3};

	localThing = localThingNull;
	localThing = (struct thing){0};

	return localThing.counter;
}

#include <stdlib.h>

struct field {
	int field :3;
	/* unnamed fields */
	int :0;
};

int main(void)
{
	struct field a = {0};
	struct field b = {1};
	struct field c = {2};
	struct field d = {4};

	printf("%08x %08x %08x %08x\n", a, b, c, d);

	return 0;
}

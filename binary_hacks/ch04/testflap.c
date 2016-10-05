#include <stdio.h>

static char onbss[128];

int main() {
	char onstack[128] = {0};
	int dummy;

	dummy = onbss[128]; // off-by-one bug
	dummy = onstack[128]; // ditto.

	return 0;
}

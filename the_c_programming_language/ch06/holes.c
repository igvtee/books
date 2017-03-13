#include <stdio.h>

struct holes {
	char c;
	int i;
};

int main(void)
{
	printf("sizeof struct holes is %zd\n", sizeof(struct holes));
	return 0;
}

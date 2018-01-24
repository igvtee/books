#include <stdio.h>
#include <stddef.h>

struct bar {
    int foo0;
    int foo1;
    int foo2;
    long long bar;
};

int main(void)
{
	printf("offset of bar is %zu\n", offsetof(struct bar, bar));
	printf("sizeof struct bar is %zu\n", sizeof(struct bar));

	return 0;
}

#include <stdio.h>
#include <stddef.h>

#pragma pack(4)
struct bar {
    int foo0;
    int foo1;
    int foo2;
    long long bar;
};
#pragma pack()

#pragma pack(push, 4)
struct foo {
    int foo0;
    int foo1;
    int foo2;
    long long foo;
};
#pragma pack(pop)

int main(void)
{
	printf("offset of bar is %zu\n", offsetof(struct bar, bar));
	printf("sizeof struct bar is %zu\n", sizeof(struct bar));

	printf("offset of foo is %zu\n", offsetof(struct foo, foo));
	printf("sizeof struct foo is %zu\n", sizeof(struct foo));

	return 0;
}

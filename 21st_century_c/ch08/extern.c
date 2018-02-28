#include <stdio.h>

extern int sint;
void test1();
void test2();

int main()
{
	test1();
	printf("%d\n", sint);
	test2();
	printf("%d\n", sint);
}

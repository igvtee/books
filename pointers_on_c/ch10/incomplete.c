#include <stdio.h>

struct B;

struct A {
	struct B *partner;
	/* other declarations */
};

struct B {
	struct A *partner;
	/* other declarations */
};

int main(void)
{
	struct A a;
	struct B b;

	return 0;
}

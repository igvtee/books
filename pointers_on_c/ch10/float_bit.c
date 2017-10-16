#include <stdio.h>

union FLOAT {
	float value;
	unsigned uvalue;
	struct {
		unsigned num	:24;
		unsigned exp	:7;
		unsigned sign	:1;
	} bit;
};

int main(void)
{
	union FLOAT a, b;

	a.value = 1;
	b.value = -1;

	printf("%f:%08x: %x %x %x\n", a.value, a.uvalue, a.bit.sign,
			a.bit.exp, a.bit.num);
	printf("%f:%08x: %x %x %x\n", b.value, b.uvalue, b.bit.sign,
			b.bit.exp, b.bit.num);

	return 0;
}

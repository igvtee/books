#include <stdio.h>

unsigned int reverse_bits(unsigned int value)
{
	unsigned int count = 1, rvalue = 0;

	while (count) {
		rvalue <<= 1;
		if (value & 1)
			rvalue |= 1;
		value >>= 1;
		count <<= 1;
	}

	return rvalue;
}

int main(void)
{
	unsigned int value = 25, rvalue;

	rvalue = reverse_bits(value);
	printf("value:\t%u\t\t%#010x\n", value, value);
	printf("rvalue:\t%u\t%#010x\n", rvalue, rvalue);

	return 0;
}

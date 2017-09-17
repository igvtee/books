#include <stdio.h>

void set_bit(char bit_array[], unsigned bit_number)
{
	int idx = bit_number >> 3;

	bit_number &= 0x7;
	bit_array[idx] |= 1 << (7 - bit_number);
}

void clear_bit(char bit_array[], unsigned bit_number)
{
	int idx = bit_number >> 3;

	bit_number &= 0x7;
	bit_array[idx] &= ~(1 << (7 - bit_number));
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
	value ? set_bit(bit_array, bit_number) :
		clear_bit(bit_array, bit_number);
}

int test_bit(char bit_array[], unsigned bit_number)
{
	int idx = bit_number >> 3;

	bit_number &= 0x7;
	return (bit_array[idx] >> (7 - bit_number)) & 1;
}

#ifndef __BITS_LIB__
int main(void)
{
	char array[4] = {0};
	unsigned bit = 14;

	set_bit(array, bit);
	printf("%#010x\n", *(unsigned int *)array);

	clear_bit(array, bit);
	printf("%#010x\n", *(unsigned int *)array);

	assign_bit(array, bit, 1);
	assign_bit(array, bit-1, 1);
	printf("%#010x\n", *(unsigned int *)array);

	printf("bit %d is %d\n", bit, test_bit(array, bit));

	return 0;
}
#endif

#include <stdio.h>

int store_bit_field(int original_value, int value_to_store,
		    unsigned starting_bit, unsigned ending_bit)
{
	unsigned mask = ~0;

	mask <<= (31 - starting_bit);
	mask >>= (31 - (starting_bit - ending_bit));
	mask <<= ending_bit;

	original_value &= ~mask;
	value_to_store <<= ending_bit;
	value_to_store &= mask;

	return original_value | value_to_store;
}

int main(void)
{
	printf("0x%x 0x%x 0x%x\n", 0x0, 0x1,
	       store_bit_field(0x0, 0x1, 4, 4));
	printf("0x%x 0x%x 0x%x\n", 0xffff, 0x123,
	       store_bit_field(0xffff, 0x123, 15, 4));
	printf("0x%x 0x%x 0x%x\n", 0xffff, 0x123,
	       store_bit_field(0xffff, 0x123, 13, 9));

	return 0;
}

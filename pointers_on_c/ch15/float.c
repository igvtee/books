#include <stdio.h>
#include <math.h>

union fvalue {
	float f;
	struct {
#if __BYTE_ORDER == __LITTLE_ENDIAN
		unsigned fraction:23;
		unsigned exponent:8;
		unsigned sign:1;
#elif __BYTE_ORDER == __BIG_ENDIAN
		unsigned sign:1;
		unsigned exponent:8;
		unsigned fraction:23;
#else
#error unknown byte order
#endif
	} value;
};

void printf_float(union fvalue fvalue)
{
	printf("%f : %#08x\n", fvalue.f, *(unsigned *)&fvalue.f);
	printf("%x %d %06x\n",
			fvalue.value.sign,
			(int)fvalue.value.exponent - 127,
			fvalue.value.fraction);
}

int main(void)
{
	float val = 1.405;
	union fvalue fvalue = { 1.405 };
	float rounded_down, nearest, rounded_up;

	/* round to nearest and ties to even */
	printf("%.3f\n", val);
	printf("%.2f\n", val);
	putchar('\n');

	printf("%f %.2f\n", 0.005, 0.005); /* 0.01 */
	printf("%f %.2f\n", 0.015, 0.015); /* 0.01 */
	printf("%f %.2f\n", 0.025, 0.025); /* 0.03 */
	printf("%f %.2f\n", 0.035, 0.035); /* 0.04 */
	printf("%f %.2f\n", 0.045, 0.045); /* 0.04 */
	printf("%f %.2f\n", 0.055, 0.055); /* 0.06 */
	printf("%f %.2f\n", 0.065, 0.065); /* 0.07 */
	printf("%f %.2f\n", 0.075, 0.075); /* 0.07 */
	printf("%f %.2f\n", 0.085, 0.085); /* 0.09 */
	printf("%f %.2f\n", 0.095, 0.095); /* 0.10 */
	putchar('\n');

	val = 0.015;
	rounded_down = floorf(val * 100) / 100;
	nearest = roundf(val * 100) / 100;
	rounded_up = ceilf(val * 100) / 100;
	printf("val: %f\nrounded_down: %f\nnearest: %f\nrounded_up: %f\n",
			val, rounded_down, nearest, rounded_up);

	return 0;
}

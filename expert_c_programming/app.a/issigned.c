#include <stdio.h>

#define ISUNSIGNED(a) (a >= 0 && (typeof(a)) ~a >= 0)
#define ISUNSIGNEDTYPE(type) ((type)(-1) > 0)

int main(void)
{
	char c = 0;
	unsigned char w = 0;

	printf("char value 'c' is %ssigned type\n",
			ISUNSIGNED(c) ? "un" : "");
	printf("unsigned char value 'w' is %ssigned type\n",
			ISUNSIGNED(w) ? "un" : "");

	printf("char is %ssigned type\n",
			ISUNSIGNEDTYPE(char) ? "un" : "");
	printf("unsigned char is %ssigned type\n",
			ISUNSIGNEDTYPE(unsigned char) ? "un" : "");

	return 0;
}

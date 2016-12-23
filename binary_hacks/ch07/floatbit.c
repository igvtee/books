#include <stdio.h>

int main(void)
{
	unsigned int i;
	float f;

	i = 0xbfe00000u; /* -1.75 */
//	i = 0xbf900000u; /* -1.125 */
	printf("%x\n", i);

	f = *((float *)&i);
	printf("%g\n", f);
	return 0;
}

#include <stdio.h>

#define	KEYWORD		01
#define	EXTERNAL	02
#define	STATIC		04
//enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };

struct flags {
	unsigned int is_keyword	: 1;
	unsigned int is_extern	: 1;
	unsigned int is_static	: 1;
	unsigned int		: 0;	/* force alignment at the next word boundary */
};

int main(void)
{
	unsigned int flags1 = 0x55555555;
	struct flags flags2 = { 0, 1, 0};

	/* turns on */
	flags1 |= EXTERNAL | STATIC;
	printf("%08x\n", flags1);

	/* turns off */
	flags1 &= ~(EXTERNAL | STATIC);

	/* if true if both bits are off */
	if ((flags1 & (EXTERNAL | STATIC)) == 0)
		printf("%08x\n", flags1);

	/* turns on */
	flags2.is_extern = flags2.is_static = 1;
	printf("%08x\n", *(unsigned int *)&flags2);

	/* turns off */
	flags2.is_extern = flags2.is_static = 0;
	printf("%08x\n", *(unsigned int *)&flags2);

	/* if true if both bits are off */
	if (flags2.is_extern == 0 && flags2.is_static == 0)
		printf("%08x\n", *(unsigned int *)&flags2);

	return 0;
}

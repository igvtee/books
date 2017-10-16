#include <stdio.h>
#include <stddef.h>

struct CHAR {
	unsigned ch : 7;
	unsigned font : 6;
	unsigned size : 19;
};

int main(void)
{
	/* error */
	printf("offset\tch: %zu\n\tfont: %zu\n\tsize: %zu\n",
			offsetof(struct CHAR, ch),
			offsetof(struct CHAR, font),
			offsetof(struct CHAR, size));
	return 0;
}

#include <stdio.h>
#include <stddef.h>

struct ALIGN {
	char a;
	int b;
	char c;
};

struct ALIGN2 {
	int b;
	char a;
	char c;
};

int main(void)
{
	printf("ALIGN: %zu, ALIGN2: %zu\n",
			sizeof(struct ALIGN),
			sizeof(struct ALIGN2));
	printf("offsetof ALIGN b: %zu\n",
			offsetof(struct ALIGN, b));

	return 0;
}

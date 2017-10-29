#include <stdio.h>

int main(void)
{
	printf("%s\n", "xyz" + 1);
	printf("%c\n", *"xyz");
	printf("%c\n", "xyz"[2]);
	printf("%c\n", *("xyz" + 4));

	return 0;
}

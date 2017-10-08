#include <stdio.h>

int main(void)
{
	char message1[] = "Hello";
	const char *message2 = "Hello";

	printf("%s %s\n", message1, message2);

	return 0;
}

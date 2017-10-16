#include <stdio.h>
#include <string.h>

int main(void)
{
	int len1, len2;
	char buffer[] = "25,142,330,Smith,J,239-4123";

	len1 = strspn(buffer, "0123456789");
	len2 = strspn(buffer, ",0123456789");

	printf("%s\n%d\n%d\n", buffer, len1, len2);

	return 0;
}

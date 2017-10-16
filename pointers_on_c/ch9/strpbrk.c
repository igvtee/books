#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[20] = "Hello there, honey.";
	char *ans;

	ans = strpbrk(string, "aeiou");
	if (ans)
		printf("%c\n", *ans);

	return 0;
}

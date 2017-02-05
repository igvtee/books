#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main(void)
{
	char data[] = "abcdef";
	/* comma ',' operator assign */
	int i = (1, 2, 3, 4);

	reverse(data);
	printf("%d %s\n", i, data);

	return 0;
}

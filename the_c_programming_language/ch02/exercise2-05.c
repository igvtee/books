#include <stdio.h>
/* like strpbrk function */

/* any: return first location in s1 where any char form s2 occurs */
int any(const char s1[], const char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])	/* match found? */
				return i;	/* location first match */
	return -1;	/* otherwise, no match */
}

int main(void)
{
	const char text[] = "Hello world!";

	printf("%s %d\n", text, any(text, "or"));

	return 0;
}

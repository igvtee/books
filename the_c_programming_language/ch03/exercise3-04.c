#include <stdio.h>
#include <string.h>
#include <limits.h>

#define abs(x)	((x) < 0 ? -(x) : (x))
void reverse(char s[]);

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;

	sign = n;	/* record sign */
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = abs(n % 10) + '0';	/* get next digit */
	} while ((n /= 10) != 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

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
	char data[16];

	itoa(INT_MIN, data);
	printf("%d %s\n", INT_MIN, data);

	return 0;
}

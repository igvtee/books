#include <stdio.h>
#include <string.h>

void reverse(char s[]);

/* itob: convert n to characters in s - base b */
void itob(int n, char s[], int b)
{
	int i, j, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;	/* make n positive */
	i = 0;
	do {	/* generate digits in reverse order */
		j = n % b;	/* get next digit */
		s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
	} while ((n /= b) > 0);	/* delete it */
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
	int num = -1234;

	itob(num, data, 16);
	printf("%d %s\n", num, data);

	return 0;
}

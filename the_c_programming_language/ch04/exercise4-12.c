#include <stdio.h>
#include <math.h>

/* itoa: convert n to characters in s; recursive */
void itoa(int n, char s[])
{
	static int i;

	if (n / 10)
		itoa(n / 10, s);
	else {
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}

int main(void)
{
	int data = -1234;
	char s[32];

	itoa(data, s);
	printf("%d %s\n", data, s);

	return 0;
}

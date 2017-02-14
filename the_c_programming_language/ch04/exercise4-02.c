#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int exp, i, sign;

	for (i = 0; isspace(s[i]); i++)	/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;

	if (s[i] == 'e' || s[i] == 'E') {
		sign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (exp = 0; isdigit(s[i]); i++)
			exp = 10.0 * exp + (s[i] - '0');
		if (sign == 1)
			while (exp-- > 0)	/* positive exponent */
				val *= 10;
		else
			while (exp-- > 0)	/* negative exponent */
				val /= 10;
	}
	return val;
}

int main(void)
{
	char data[] = "-123.456e2";
	char data1[] = "-123.456e-2";

	printf("%s %lf\n", data, atof(data));
	printf("%s %lf\n", data1, atof(data1));

	return 0;
}

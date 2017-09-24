#include <stdio.h>
#include <string.h>

const char * const number_19[] = {"zero", "one", "two", "three",
	"four", "five", "six", "seven", "eight", "nine", "ten",
	"eleven", "twelve", "thirteen", "fourteen", "fifteen",
	"sixteen", "seventeen", "eighteen", "nineteen"};
const char * const number_x0[] = {"twenty", "thirty", "forty",
	"fifty", "sizty", "seventy", "eighty", "ninety"};

void written_amount(unsigned int amount, char *buff)
{
	int offset;
	unsigned int tmp, base = 0;
	const char *str;

	if (amount < 20)
		strcpy(buff, number_19[amount]);
	else if (amount < 100) {
		tmp = (amount / 10) - 2;
		offset = sprintf(buff, "%s", number_x0[tmp]);
		if ((tmp = amount % 10)) {
			buff += offset;
			*buff++ = ' ';
			strcpy(buff, number_19[tmp]);
		}
	} else if (amount < 1000) {
		base = 100;
		str = "hundred";
	} else if (amount < 1000000U) {
		base = 1000;
		str = "thousand";
	} else if (amount < 100000000U) {
		base = 100000;
		str = "million";
	} else if (amount < 10000000000U) {
		base = 10000000;
		str = "billion";
	}

	if (base) {
		if ((tmp = (amount / base))) {
			written_amount(tmp, buff);
			strcat(buff, " ");
			strcat(buff, str);
			buff += strlen(buff);
		}
		if (tmp = amount % base) {
			*buff++ = ' ';
			written_amount(tmp, buff);
		}
	}
}

int main(void)
{
	char buff[128];
	unsigned int num = 8952123;

	written_amount(num, buff);
	printf("%u: %s\n", num, buff);

	return 0;
}

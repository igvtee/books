#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int idx;
	int totcal;
	int (*chartype[])(int c) = {
		iscntrl,
		isspace,
		isdigit,
		islower,
		isupper,
		ispunct,
		NULL
	};
	unsigned int count[7] = {0};
	char *name[] = {
		"cntrl", "space", "digit", "lower", "upper",
		"punct", "nonprint"
	};

	while ((ch = getchar()) != EOF) {
		for (idx = 0; chartype[idx] != NULL; idx++) {
			if (chartype[idx](ch) != 0) {
				count[idx]++;
				break;
			}
		}
		if (chartype[idx] == NULL)
			count[idx]++;
	}

	totcal = 0;
	for (idx = 0; idx < 7; idx++) {
		totcal += count[idx];
	}

	for (idx = 0; idx < 7; idx++) {
		printf("%-10s: %d %%\n", name[idx],
				count[idx]*100/totcal);
	}

	return 0;
}

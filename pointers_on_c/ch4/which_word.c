#include <stdio.h>

int main(void)
{
	int which_word;
	char *word;

	if (scanf("%d", &which_word) != 1)
	    return 1;

	switch (which_word) {
	case 1:
		word = "who";
		break;
	case 2:
		word = "what";
		break;
	case 3:
		word = "when";
		break;
	case 4:
		word = "where";
		break;
	case 5:
		word = "why";
		break;
	default:
		word = "don't know";
		break;
	}

	printf("%s\n", word);

	return 0;
}

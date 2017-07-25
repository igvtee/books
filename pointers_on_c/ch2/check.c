#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c;
	int brace = 0;

	/* read char */
	while ((c = getchar()) != EOF) {
		switch (c) {
		case '{':
			brace++;
			break;
		case '}':
			brace--;
			break;
		default:
			break;
		}

		/* check invalid '}' */
		if (brace < 0) {
			printf("unmatch }\n");
			exit(EXIT_FAILURE);
		}
	}

	/* check pair '{}' */
	if (brace != 0) {
		printf("unmatch {,}\n");
		exit(EXIT_FAILURE);
	}

	printf("ok\n");
	return EXIT_SUCCESS;
}

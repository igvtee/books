#include <stdio.h>
#include <locale.h>

int main(void)
{
	int i;
	char *locname[] = {"LC_ALL", "LC_COLLATE", "LC_CTYPE",
		"LC_MONETARY", "LC_NUMERIC", "LC_TIME"};
	int loc[] = {LC_ALL, LC_COLLATE, LC_CTYPE, LC_MONETARY,
		LC_NUMERIC, LC_TIME};

	for (i = 0; i < sizeof(loc)/sizeof(loc[0]); i++)
		printf("%s: %s\n", locname[i],
				setlocale(loc[i], NULL));

	return 0;
}

#include <stdlib.h>

#define MAXLINE	100	/* maximum line size */
#define TABINC	8	/* default tab increment size */
#define YES	1
#define NO	0

/* esettab: set tab stops in array tab */
void esettab(int argc, char *argv[], char *tab)
{
	int i, inc, pos;

	if (argc <= 1)		/* default tab stops */
		for (i = 1; i < MAXLINE; i++)
			if (i % TABINC == 0)
				tab[i] = YES;
			else
				tab[i] = NO;
	else if (argc == 3 &&	/* user providede range */
		 *argv[1] == '-' && *argv[2] == '+') {
		pos = atoi(&(*++argv)[1]);
		inc = atoi(&(*++argv)[1]);
		for (i = 1; i <= MAXLINE; i++)
			if (i != pos)
				tab[i] = NO;
			else {
				tab[i] = YES;
				pos += inc;
			}
	} else {		/* user provided tab stops */
		for (i = 1; i < MAXLINE; i++)
			tab[i] = NO;	/* turn off all tab stops */
		while (--argc > 0) {	/* walk through argument list */
			pos = atoi(*++argv);
			if (pos > 0 && pos <= MAXLINE)
				tab[pos] = YES;
		}
	}
}

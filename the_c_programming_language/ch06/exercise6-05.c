#include <string.h>
#include "nlist.h"

/* undef: remove a name and definition from the table */
void undef(char *s)
{
	int h;
	struct nlist *prev, *np;

	prev = NULL;
	h = hash(s);		/* hash value of string s */
	for (np = hashtab[h]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0)
			break;
		prev = np;	/* remember previous entry */
	}
	if (np != NULL) {	/* found name */
		if (prev == NULL)	/* first in the hash list ? */
			hashtab[h] = np->next;
		else
			prev->next = np->next;
		free((void *) np->name);
		free((void *) np->defn);
		free((void *) np);	/* free allocated structure */
	}
}

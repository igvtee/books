#ifndef __NLIST_H_
#define __NLIST_H_

struct nlist {		/* table entry: */
	struct nlist *next;	/* next entry in chain */
	char *name;		/* defined name */
	char *defn;		/* replacement text */
};

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *);

extern struct nlist *hashtab[];	/* pointer table */

#endif // __NLIST_H_

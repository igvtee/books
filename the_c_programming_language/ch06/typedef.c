#include <stdlib.h>

typedef int Length;
typedef char *String;

typedef struct tnode *Treeptr;
typedef struct tnode {			/* the tree node */
	char *word;		/* points to the text */
	int count;		/* number of occurrences */
	struct tnode *left;	/* left child */
	struct tnode *right;	/* right child */
} Treenode;

typedef int (*PFI)(char *, char *);

Treeptr talloc(void)
{
	return (Treeptr) malloc(sizeof(Treenode));
}

int main(void)
{
	Length len, maxlen;
	Length *lengths[4];
	String p, lineptr[6], alloc(int);
	int strcmp(String, String);
	Treeptr tp;
	PFI strcomp, numcomp;

	p = (String) malloc(100);
	tp = talloc();

	return 0;
}

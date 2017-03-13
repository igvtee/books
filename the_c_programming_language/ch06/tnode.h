#ifndef __TNODE_H_
#define __TNODE_H_

struct tnode {			/* the tree node */
	char *word;		/* points to the text */
	int count;		/* number of occurrences */
	struct tnode *left;	/* left child */
	struct tnode *right;	/* right child */
};

#endif //__TNODE_H_

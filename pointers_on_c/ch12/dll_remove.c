#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list_node.h"

int dll_insert( register Node *rootp, int value );

int dll_remove(struct NODE *rootp, struct NODE *node)
{
	register Node	*this;
	register Node	*next;
	register Node	*nnext;

	for( this = rootp; (next = this->fwd) != NULL; this = next ){
		if(next == node)
			break;
	}
	/* not found */
	if (next == NULL)
		return 0;

	nnext = next->fwd;
	this->fwd = nnext;

	if (nnext != NULL)
		if (this != rootp)
			nnext->bwd = this;
		else
			nnext->bwd = NULL;
	else
		if (this != rootp)
			rootp->bwd = this;
		else
			rootp->bwd = NULL;
	free(node);
	
	return 1;
}

int main(void)
{
	int ret;
	struct NODE root = {NULL, NULL, 0};
	struct NODE *node = NULL;

	ret = dll_remove(&root, node);
	printf("remove empty node ret: %d\n", ret);

	dll_insert(&root, 3);
	dll_insert(&root, 4);
	node = root.fwd;
	ret = dll_remove(&root, node);
	printf("remove mid node ret: %d, fwd: %p, bwd: %p\n",
			ret, root.fwd, root.bwd);

	node = root.fwd;
	ret = dll_remove(&root, node);
	printf("remove last node ret: %d, fwd: %p, bwd: %p\n",
			ret, root.fwd, root.bwd);

	return 0;
}

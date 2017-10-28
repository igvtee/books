/*
** Insert a value into a doubly linked list.  rootp is a pointer to
** the root node, and value is the new value to be inserted.
** Returns: 0 if the value is already in the list, -1 if there was
** no memory to create a new node, 1 if the value was added
** successfully.
*/
#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list_node.h"

int
dll_insert(Node **frontp, Node **rearp, int value)
{
	register Node	**fwdp;
	register Node	*next;
	register Node	*newnode;

	fwdp = frontp;
	while ((next = *fwdp) != NULL) {
		if( next->value == value )
			return 0;
		if( next->value > value )
			break;
		fwdp = &next->fwd;
	}
	newnode = (Node *)malloc( sizeof( Node ) );
	if( newnode == NULL )
		return -1;
	newnode->value = value;

	/*
	** Add the new node to the list.
	*/
	newnode->fwd = next;
	*fwdp = newnode;

	if( fwdp != frontp)
		if( next != NULL )
			newnode->bwd = next->bwd;
		else
			newnode->bwd = *rearp;
	else
		newnode->bwd = NULL;

	if( next != NULL )
		next->bwd = newnode;
	else
		*rearp = newnode;

	return 1;
}

int main(void)
{
	Node root = {NULL, NULL, 0};
	Node *nodep;

	dll_insert(&root.fwd, &root.bwd, 1);
	dll_insert(&root.fwd, &root.bwd, 2);
	dll_insert(&root.fwd, &root.bwd, 3);
	dll_insert(&root.fwd, &root.bwd, 4);
	dll_insert(&root.fwd, &root.bwd, 5);
	dll_insert(&root.fwd, &root.bwd, 6);
	dll_insert(&root.fwd, &root.bwd, 7);
	dll_insert(&root.fwd, &root.bwd, 8);
	dll_insert(&root.fwd, &root.bwd, 9);
	dll_insert(&root.fwd, &root.bwd, 10);

	nodep = root.fwd;
	while (nodep) {
		printf("%d ", nodep->value);
		nodep = nodep->fwd;
	}
	putchar('\n');

	return 0;
}

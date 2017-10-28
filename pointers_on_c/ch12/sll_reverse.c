#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list_node.h"

int sll_insert( register Node **linkp, int new_value );

struct NODE *sll_reverse(struct NODE *first)
{
	struct NODE *next, *nnext;

	if (!first)
		return NULL;

	next = first->link;
	first->link = 0;
	while (next) {
		nnext = next->link;
		next->link = first;
		first = next;
		next = nnext;
	}

	return first;
}

int main(void)
{
	Node *link = NULL;

	sll_insert(&link, 9);
	sll_insert(&link, 2);
	sll_insert(&link, 4);
	sll_insert(&link, 1);
	sll_insert(&link, 3);
	sll_insert(&link, 8);
	sll_insert(&link, 5);
	sll_insert(&link, 11);
	sll_print(link);

	link = sll_reverse(link);
	sll_print(link);

	return 0;
}

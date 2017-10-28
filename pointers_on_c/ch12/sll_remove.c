#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list_node.h"

int sll_insert( register Node **linkp, int new_value );

int sll_remove(struct NODE **rootp, struct NODE *node)
{
	int ret = 0;
	struct NODE *this = *rootp;
	struct NODE *prev = NULL;

	while (this) {
		if (this == node) {
			if (prev)
				prev->link = this->link;
			else
				*rootp = this->link;
			free(node);
			ret = 1;
			break;
		}
		prev = this;
		this = this->link;
	}

	return ret;
}

int main(void)
{
	Node *link = NULL;
	Node tnode;

	sll_insert(&link, 9);
	sll_insert(&link, 2);
	sll_insert(&link, 4);
	sll_insert(&link, 1);
	sll_insert(&link, 3);
	sll_insert(&link, 8);
	sll_insert(&link, 5);
	sll_insert(&link, 11);
	sll_print(link);

	/* remove first node */
	sll_remove(&link, link);
	sll_print(link);

	/* remove non exist node */
	sll_remove(&link, &tnode);
	sll_print(link);

	return 0;
}

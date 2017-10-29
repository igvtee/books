#include <stdio.h>
#include "singly_linked_list_node.h"

int sll_insert( register Node **linkp, int new_value );

int sll_callback(Node *node, int (*callback)(Node *node))
{
	int ret = 0;

	while (node) {
		if ((ret = callback(node)))
			break;
		node = node->link;
	}

	return ret;
}

int printvalue(Node *node)
{
	printf("%d\n", node->value);
	return 0;
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

	sll_callback(link, printvalue);

	return 0;
}

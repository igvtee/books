#include <stdio.h>
#include "singly_linked_list_node.h"

void sll_print(struct NODE *first)
{
	while (first) {
		printf("%d ", first->value);
		first = first->link;
	}
	putchar('\n');
}

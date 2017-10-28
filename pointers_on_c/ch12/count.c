#include <stdio.h>
#include "singly_linked_list_node.h"

extern int sll_insert( register Node **linkp, int new_value );

int sll_count(register Node *link)
{
	int cnt = 0;

	while (link != NULL) {
		link = link->link;
		cnt++;
	}

	return cnt;
}

Node *sll_find(register Node *link, int value)
{
	while (link != NULL) {
		if (value == link->value)
			return link;
		link = link->link;
	}

	return NULL;
}

int main(void)
{
	Node *link = NULL;
	int val = 4;

	sll_insert(&link, 9);
	sll_insert(&link, 2);
	sll_insert(&link, 4);
	sll_insert(&link, 1);
	sll_insert(&link, 3);
	sll_insert(&link, 8);
	sll_insert(&link, 5);
	sll_insert(&link, 11);

	printf("node count: %d\n", sll_count(link));
	printf("find node value %d: %p\n", val, sll_find(link, val));

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

struct NODE {
	int data;
	SLIST_ENTRY(NODE) field;
};

SLIST_HEAD(HEAD, NODE);

int main(void)
{
	int i;
	struct HEAD head = SLIST_HEAD_INITIALIZER(head);
	struct NODE *element;
	struct NODE *p1, *p2;
	struct NODE *loop, *end;
	
	for (i = 0; i < 10; i++) {
		element = (struct NODE *)calloc(1, sizeof(*element));
		if (!element) {
			printf("malloc element %d failed\n", i);
			exit(1);
		}
		/* save to loop form here */
		if (i == 0)
			end = element;
		if (i == 5)
			loop = element;
		element->data = i;
		SLIST_INSERT_HEAD(&head, element, field);
	}

	// add loop elements
	end->field.sle_next = loop;
	
	/* find first and third element */
	p1 = SLIST_FIRST(&head);
	if (p1 != NULL) {
		p2 = SLIST_NEXT(p1, field);
		if (p2 != NULL)
			p2 = SLIST_NEXT(p2, field);
	}

	// loop detect
	while (p1 != NULL && p2 != NULL) {
		if (p1 == p2)
			break;
		p1 = SLIST_NEXT(p1, field);
		p2 = SLIST_NEXT(p2, field);
		if (p2 != NULL)
			p2 = SLIST_NEXT(p2, field);
	}

	if (p1 == NULL || p2 == NULL)
		printf("loop not detect\n");
	else
		printf("loop detect data %d\n", p1->data);

	/*
	   SLIST_FOREACH(element, &head, field) {
	   printf("element %d\n", element->data);
	   }

	// Remove all elements
	while (!SLIST_EMPTY(&head)) {
		element = SLIST_FIRST(&head);
		SLIST_REMOVE(&head, element, NODE, field);
		free(element);
	}
	*/

	return 0;
}

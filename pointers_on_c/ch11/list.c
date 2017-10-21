#include <stdio.h>
#include <stdlib.h>

struct LIST {
	int value;
	struct LIST *next;
};

int main(void)
{
	struct LIST *head;
	struct LIST *array = malloc(sizeof(*array) * 3);

	head = array;
	array[0].value = 5;
	array[0].next = &array[1];
	array[1].value = 10;
	array[1].next = &array[2];
	array[2].value = 15;
	array[2].next = NULL;

	return 0;
}

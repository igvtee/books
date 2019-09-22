#include <stdlib.h>
#include <stdio.h>
#include <safe_list.h>

struct number {
	struct safe_list list;
	int num;
};

void number_add(struct safe_list *head, int num)
{
	struct number *new = malloc(sizeof(*new));
	new->num = num;
	safe_list_add(&new->list, head);
}

int print_cb(void *ctx __attribute__((unused)), struct safe_list *list)
{
	struct number *num;

	num = list_entry(list, __typeof__(*num), list);
	printf("%d ", num->num);

	return 0;
}

void number_print(struct safe_list *head)
{
	safe_list_for_each(head, print_cb, NULL);
	putchar('\n');
}

int main(void)
{
	int i;
	SAFE_LIST(list);

	for (i = 0; i < 5; i++)
		number_add(&list, i);
	number_print(&list);

	return 0;
}

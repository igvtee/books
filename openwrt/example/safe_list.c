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

void number_print(struct safe_list *head)
{
	struct number *num;

	list_for_each_entry(num, &head->list, list.list)
		printf("%d ", num->num);
	putchar('\n');
}

int del_num_cb(void *ctx __attribute__((unused)), struct safe_list *list)
{
	struct number *num;
	int del_num = (intptr_t) ctx;

	num = list_entry(list, __typeof__(*num), list);
	if (num->num == del_num) {
		safe_list_del(list);
		free(num);
	}

	return 0;
}

void number_del_num(struct safe_list *head, intptr_t del_num)
{
	safe_list_for_each(head, del_num_cb, (void *) del_num);
}

void number_clean(struct safe_list *head)
{
	struct number *num;

	while (!list_empty(&head->list)) {
		num = list_first_entry(&head->list, struct number, list.list);
		safe_list_del(&num->list);
		free(num);
	}
}

int main(void)
{
	int i;
	SAFE_LIST(list);

	for (i = 0; i < 5; i++)
		number_add(&list, i);
	number_print(&list);

	number_del_num(&list, 3);
	number_print(&list);

	number_clean(&list);

	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <safe_list.h>

SAFE_LIST(glist);

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

int pr_num_cb(void *ctx __attribute__((unused)), struct safe_list *list)
{
	struct number *num;
	int n = (intptr_t) ctx;

	num = list_entry(list, __typeof__(*num), list);
	if (num->num == n) {
		number_del_num(&glist, 1);
	}
	printf("%d ", num->num);

	return 0;
}

void number_pr_test(struct safe_list *head)
{
	safe_list_for_each(head, pr_num_cb, (void *) 0);
	putchar('\n');
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

	for (i = 0; i < 5; i++)
		number_add(&glist, i);
	number_print(&glist);

	number_pr_test(&glist);

	number_clean(&glist);

	return 0;
}

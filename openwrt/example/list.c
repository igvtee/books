#include <stdlib.h>
#include <stdio.h>
#include <list.h>

struct number {
	struct list_head list;
	int num;
};

/* add to the 1st position */
void number_add(struct list_head *head, int num)
{
	struct number *new = malloc(sizeof(*new));
	new->num = num;
	list_add_tail(&new->list, head);
}

void number_print(struct list_head *head)
{
	struct number *num;

	list_for_each_entry(num, head, list)
		printf("%d ", num->num);
	putchar('\n');

#if 0
	list_for_each_entry_reverse(num, head, list)
		printf("%d ", num->num);
	putchar('\n');
#endif
}

void number_del(struct list_head *entry)
{
	struct number *num;

	list_del(entry);
	num = list_entry(entry, struct number, list);
	free(num);
}

void number_clean(struct list_head *head)
{
	struct number *num, *tmp;

	list_for_each_entry_safe(num, tmp, head, list) {
		list_del(&num->list);
		free(num);
	}
}

int main(void)
{
	int i;
	LIST_HEAD(from);
	LIST_HEAD(to);

	for (i = 0; i < 5; i++)
		number_add(&to, i);
	number_print(&to);

	for (; i < 10; i++)
		number_add(&from, i);
	number_print(&from);

	/* move one entry */
	list_move_tail(from.next, &to);
	number_print(&to);

	/* splice two list */
	list_splice_tail_init(&from, &to);
	number_print(&to);

	if (list_empty(&from))
		printf("from empty list now!\n");

	number_clean(&to);

	return 0;
}

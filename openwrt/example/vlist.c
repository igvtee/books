#include <stdio.h>
#include <stdlib.h>
#include <vlist.h>

struct number {
	struct vlist_node node;
	int num;
};

int avl_numcmp(const void *k1, const void *k2, void *ptr __attribute__((unused)))
{
	int nk1 = *(const int *)k1;
	int nk2 = *(const int *)k2;

	if (nk1 > nk2)
		return 1;
	else if (nk1 < nk2)
		return -1;
	else
		return 0;
}

int number_add(struct vlist_tree *tree, int num)
{
	struct number *new;

	new = malloc(sizeof(*new));
	if (!new)
		return 1;

	new->num = num;
	vlist_add(tree, &new->node, &new->num);
	return 0;
}

void number_del(struct vlist_tree *tree, int num)
{
	struct number *node;

	node = vlist_find(tree, &num, node, node);
	if (node)
		vlist_delete(tree, &node->node);
}

void number_print(struct vlist_tree *tree)
{
	struct number *node;

	vlist_for_each_element(tree, node, node)
		printf("%d ", node->num);
	putchar('\n');
}

void number_update(struct vlist_tree *tree  __attribute__((unused)),
		   struct vlist_node *node_new, struct vlist_node *node_old)
{
	struct number *num_old, *num_new;

	num_old = container_of(node_old, struct number, node);
	num_new = container_of(node_new, struct number, node);

	if (num_old) {
		printf("del %d\n", num_old->num);
		free(num_old);
	}

	if (num_new) {
		printf("add %d\n", num_new->num);
	}
}

int main(void)
{
	int i;
	struct vlist_tree tree = {0};

	vlist_init(&tree, avl_numcmp, number_update);
	for (i = 0; i < 5; i++)
		number_add(&tree, i);
	number_print(&tree);

	number_del(&tree, 3);
	number_print(&tree);

	vlist_update(&tree);
	for (; i < 10; i++)
		number_add(&tree, i);
	number_print(&tree);

	printf("=== flush ===\n");
	vlist_flush(&tree);
	number_print(&tree);

	vlist_flush_all(&tree);

	return 0;
}

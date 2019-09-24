#include <stdio.h>
#include <stdlib.h>
#include <avl.h>

struct number {
	struct avl_node node;
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

int number_add(struct avl_tree *tree, int num)
{
	struct number *new;

	new = malloc(sizeof(*new));
	if (!new)
		return 1;

	new->num = num;
	new->node.key = &new->num;

	avl_insert(tree, &new->node);
	return 0;
}

void number_print(struct avl_tree *tree)
{
	struct number *node;

	avl_for_each_element(tree, node, node) {
		printf("%d ", node->num);
	}
	putchar('\n');
}

void number_del(struct avl_tree *tree, int num)
{
	struct number *node;

	node = avl_find_element(tree, &num, node, node);
	if (node) {
		avl_delete(tree, &node->node);
		free(node);
	}
}

void number_find_le(struct avl_tree *tree, int num)
{
	struct number *node;

	node = avl_find_le_element(tree, &num, node, node);
	if (node)
		printf("found %d le %d\n", node->num, num);
}

void number_first(struct avl_tree *tree)
{
	struct number *node;

	node = avl_first_element(tree, node, node);
	if (node)
		printf("first is %d\n", node->num);
}

void number_print_range(struct avl_tree *tree, int beg, int end)
{
	struct number *node, *bnode, *enode;

	bnode = avl_find_ge_element(tree, &beg, node, node);
	enode = avl_find_le_element(tree, &end, node, node);
	if (!bnode || !enode)
		return;

	printf("range from %d to %d\n", beg, end);
	avl_for_element_range(bnode, enode, node, node) {
		printf("%d ", node->num);
	}
	putchar('\n');
}

void number_clean(struct avl_tree *tree)
{
	struct number *node, *next;

	avl_remove_all_elements(tree, node, node, next)
		free(node);
}

int main(void)
{
	int i;
	struct avl_tree tree;

	avl_init(&tree, avl_numcmp, false, NULL);
	for (i = 0; i < 10; i++)
		number_add(&tree, i);
	number_print(&tree);

	number_del(&tree, 3);
	number_print(&tree);

	number_find_le(&tree, 3);
	number_first(&tree);
	number_print_range(&tree, 4, 8);

	number_clean(&tree);
}

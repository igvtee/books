#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int val;
	struct s_node *next;
};

int slist_insert(struct s_node **root, int val)
{
	struct s_node **cur;
	struct s_node *entry, *new;

	cur = root;
	while ((entry = *cur) != NULL && entry->val < val) {
		cur = &entry->next;
	}
	new = malloc(sizeof(struct s_node));
	new->val = val;

	new->next = entry;
	*cur = new;
}

int slist_del_element(struct s_node **root, int val)
{
	struct s_node **cur;
	struct s_node *entry;

	for (cur = root; *cur;) {
		entry = *cur;
		if (entry->val == val) {
			*cur = entry->next;
			free(entry);
		} else
			cur = &entry->next;
	}
}

int main()
{
	struct s_node head = {0, NULL};
	struct s_node *root = &head;

	slist_insert(&root, 2);
	slist_insert(&root, 5);
	printf("del element\n");
	slist_del_element(&root, 5);
}

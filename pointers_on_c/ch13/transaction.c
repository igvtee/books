#include <stdio.h>
#include "singly_linked_list_node.h"

int trans_new(Node *list, Node **curr, Transaction *trans)
{
	return add_new_trans(list, trans);
}

int trans_delete(Node *list, Node **curr, Transaction *trans)
{
	*curr = delete_trans(list, *curr);
	return 0;
}

int trans_forward(Node *list, Node **curr, Transaction *trans)
{
	*curr = (*curr)->next;
	return 0;
}

int trans_backward(Node *list, Node **curr, Transaction *trans)
{
	*curr = (*curr)->prev;
	return 0;
}

int trans_search(Node *list, Node **curr, Transaction *trans)
{
	*curr = search(list, trans);
	return 0;
}


int trans_edit(Node *list, Node **curr, Transaction *trans)
{
	edit(*curr, trans)
	return 0;
}

int main(void)
{
	Node *list;
	Node *current;
	Transaction *transaction;
	typedef enum { NEW, DELETE, FORWARD, BACKWARD,
		SEARCH, EDIT
	} Trans_type;
	int (*trans_func[])(Node *list, Node **curr,
			Transaction *trans) = {
		trans_new,
		trans_delete,
		trans_forward,
		trans_backward,
		trans_search,
		trans_edit
	};

	if (transaction->type < NEW || transaction->type > EDIT) {
		printf("Illegal transaction type!\n");
		return 1;
	}

	trans_func[transaction->type](list, &current, transaction);

	return 0;
}

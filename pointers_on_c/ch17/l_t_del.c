/*
 * Delete a node from an linked binary search tree
 */
void delete(TREE_TYPE value)
{
	TreeNode *current;
	TreeNode **link;

	/*
	 * First, locate the value. It must exist in the tree or this routine
	 * will abort the program.
	 */
	link = &tree;

	while ((current = *link) != NULL && value != current->value) {
		if (value < current->value)
			link = &current->left;
		else
			link = &current->right;
	}
	assert(current != NULL);

	/*
	 * We've found the value. See how many children it has.
	 */
	if (current->left == NULL && current->right == NULL) {
		/*
		 * It is a leaf; no children to worry about!
		 */
		*link = NULL;
		free(current);
	} else if (current->left == NULL || current->right == NULL) {
		/*
		 * The node has only one child, so the parent will simply
		 * inherit it.
		 */
		if (current->left != NULL)
			*link = current->left;
		else
			*link = current->right;
		free(current);
	} else {
		/*
		 * The node has two children! Replace its value with the
		 * largest value from its left subtree, and then delete that
		 * node instead.
		 */
		TreeNode *this_child;
		TreeNode *next_child;

		this_child = current->left;
		next_child = this_child->right;
		while (next_child != NULL) {
			this_child = next_child;
			next_child = this_child->right;
		}

		/*
		 * Delete the child and replace the current value with
		 * this_child's value.
		 */
		value = this_child->value;
		delete(value);
		current->value = value;
	}
}

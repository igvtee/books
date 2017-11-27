/*
 * Count the number of nodes in a linked binary search tree.
 */

/*
 * This helper function takes the root of the tree we're currently working
 * on as an argument.
 */
int count_nodes( TreeNode *tree)
{
	if (tree == NULL)
		return 0;
	return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

int number_of_nodes(void)
{
	return count_nodes(tree);
}

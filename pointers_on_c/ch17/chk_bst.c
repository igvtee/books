/*
 * Check a linked binary search tree for validity.
 */

/*
 * This helper function checks the validity of one node, using minimum and
 * maximum values passed in from the caller.
 */
int check_bst_subtree(TreeNode *node, int min, int max)
{
	/*
	 * Empty trees are always valid.
	 */
	if (node == NULL)
		return TRUE;

	/*
	 * Check the validity of this node.
	 */
	if (node->value < min || node->value > max)
		return FALSE;

	/*
	 * Check the validity of the subtree.
	 */
	if (!check_bst_subtree(node->left, min, node->value - 1) ||
			!check_bst_subtree(node->right, node->value + 1, max))
		return FALSE;

	return TRUE;
}

/*
 * Check the validity of a binary search tree.
 */
int check_bst_tree(void)
{
	return check_bst_subtree(tree, INT_MIN, INT_MAX);
}

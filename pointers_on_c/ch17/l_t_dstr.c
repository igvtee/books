/*
 * Destroy a linked binary search tree.
 */

/*
 * Do one level of a post-order traverse to destroy the tree. This helper
 * function is needed to save the information of which node we're currently
 * processing; this is not a part of the chient's interface.
 */
static void do_destroy_tree(TreeNode *current)
{
	if (current != NULL) {
		do_destroy_tree(current->left);
		do_destroy_tree(current->right);
		free(current);
	}
}

/*
 * Destroy the entire tree.
 */
void destroy_tree(void)
{
	do_destroy_tree(tree);
}

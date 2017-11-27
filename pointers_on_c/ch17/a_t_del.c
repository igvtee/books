/*
 * Delete a node from an arrayed binary search tree
 */
void delete(TREE_TYPE value)
{
	int current;
	int left;
	int right;
	int left_subtree_empty;
	int right_subtree_empty;

	/*
	 * First, locate the value. It must exist in the tree or this routine
	 * will abort the program.
	 */
	current = 1;

	while (tree[current] != value) {
		if (value < tree[current])
			current = left_child(current);
		else
			current = right_child(current);
		assert(current < ARRAY_SIZE);
		assert(tree[current] != 0);
	}

	/*
	 * We've found the value. If it is a leaf, simply set it to zero.
	 * Otherwise, if its left subtree is not empty, replace the node's value
	 * with the rightmost (largest) child from its left subtree, and then
	 * delete that node. Otherwise, replace the value with the leftmost
	 * (smallest) child from its right subtree, and delete that node.
	 */
	left = left_child(current);
	right = right_child(current);
	left_subtree_empty = left > ARRAY_SIZE || tree[left] == 0;
	right_subtree_empty = right > ARRAY_SIZE || tree[right] == 0;

	if (left_subtree_empty && right_subtree_empty)
		/*
		 * The value has no children; simply set it to zero.
		 */
		tree[current] = 0;
	else {
		int this_child;
		int next_child;

		if (!left_subtree_empty) {
			/*
			 * The left subtree is nonempty. Find its rightmost
			 * child.
			 */
			this_child = left;
			next_child = right_child(this_child);

			while (next_child < ARRAY_SIZE
					&& tree[next_child] != 0) {
				this_child = next_child;
				next_child = right_child(this_child);
			}
		} else {
			/*
			 * The right subtree is nonempty. Find its leftmost
			 * child.
			 */
			this_child = right;
			next_child = left_child(this_child);

			while (next_child < ARRAY_SIZE
					&& tree[next_child] != 0) {
				this_child = next_child;
				next_child = left_child(this_child);
			}
		}

		/*
		 * Delete the child and replace the current value with
		 * this_child's value.
		 */
		value = tree[this_child];
		delete(value);
		tree[current] = value;
	}
}

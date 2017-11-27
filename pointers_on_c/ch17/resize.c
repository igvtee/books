/*
 * Resize the array holding the stack.
 */

void resize_stack(size_t new_size)
{
	STACK_TYPE *old_stack;
	int i;

	/*
	 * Make sure the new size is large enough to hold the data already on
	 * the stack. Then save the pointer to the old array and create a new
	 * one of the right size.
	 */
	assert(new_size > top_element);
	old_stack = stack;
	stack = (STACK_TYPE *)malloc(new_size * sizeof(STACK_TYPE));
	assert(stack != NULL);
	stack_size = new_size;

	/*
	 * Copy values from the old array to the new one and then free the old
	 * memory.
	 */
	for (i = 0; i <= top_element; i += 1)
		stack[i] = old_stack[i];
	free(old_stack);
}

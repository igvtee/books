/*
 * Do an insertion sort to order the elements in an array.
 */

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void insertion_sort(void *base, size_t n_elements, size_t el_size,
int (*compare)(void const *x, void const *y))
{
	char *array;
	char *temp;
	int i;
	int next_element;

	/*
	 * Copy base address into a char * so we can do pointer arithmetic.
	 * Then get a temporary array large enough to hold a single element.
	 */
	array = base;
	temp = malloc(el_size);
	assert(temp != NULL);

	/*
	 * The first element in the array is already sorted. Insert the
	 * remaining ones one by one.
	 */
	for (next_element = 1; next_element < n_elements; next_element += 1) {
		char *i_ptr = array;
		char *next_ptr = array + next_element * el_size;

		/*
		 * Find the right place to insert the next element.
		 */
		for (i = 0; i < next_element; i += 1, i_ptr += el_size)
			if (compare(next_ptr, i_ptr) < 0)
				break;

		/*
		 * If we went all the way to the end of the sorted part of the
		 * array, then the next element should go after those that are
		 * already sorted. That's where it is right now, so we're done.
		 */
		if (i == next_element)
			continue;

		/*
		 * Otherwise, we must insert the next element before the one
		 * that i points to. First, copy the next element into the
		 * temporary array.
		 */
		memcpy(temp, next_ptr, el_size);

		/*
		 * Now copy the elements from i to the end of the sorted part of
		 * the array to the right one place.
		 */
		memmove(i_ptr + el_size, i_ptr, (next_element - i) * el_size);

		/*
		 * Finally, the next element is inserted.
		 */
		memcpy(i_ptr, temp, el_size);
	}

	free(temp);
}

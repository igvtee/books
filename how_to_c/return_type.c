#include <stdlib.h>

typedef enum growthResult {
	GROWTH_RESULT_SUCCESS = 1,
	GROWTH_RESULT_FAILURE_GROW_NOT_NECESSARY,
	GROWTH_RESULT_FAILURE_ALLOCATION_FAILED
} growthResult;

growthResult growthOptional(void **_grow, size_t currentLen, size_t newLen) {
	void *grow = *_grow;
	if (newLen > currentLen) {
		void *newGrow = realloc(grow, newLen);
		if (newGrow) {
			/* resize success */
			*_grow = newGrow;
			return GROWTH_RESULT_SUCCESS;
		}

		/* resize failure, don't remove data because we can signal error */
		return GROWTH_RESULT_FAILURE_ALLOCATION_FAILED;
	}

	return GROWTH_RESULT_FAILURE_GROW_NOT_NECESSARY;
}

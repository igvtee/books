#include <stdio.h>

void sort_goto(void)
{
	int i = 0, j;
outer_next:
	if (i >= NUM_ELEMENTS - 1)
		goto outer_end;
	j = i + 1;
inner_next:
	if (j >= NUM_ELEMENTS)
		got inner_end;
	if (value[i] <= value[j])
		goto no_swap;
	temp = value[i];
	value[i] = value[j];
	value[j] = temp;
no_swap:
	j += 1;
	goto inner_next;
inner_end:
	i += 1;
	goto outer_next;
outer_end:
	;
}

void sort(void)
{
	for (i = 0; i < NUM_ELEMENTS - 1; i += 1) {
		for (j = i + 1; j < NUM_ELEMENTS; j += 1) {
			if (value[i] > value[j]) {
				temp = value[i];
				value[i] = value[j];
				value[j] = temp;
			}
		}
	}
}

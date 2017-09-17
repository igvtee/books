#include <stdio.h>
#include <string.h>
#include "bit.h"

#define MAX_NUM 1000/8

/*
 * 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
 * 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39
 * 3 5 7 9x 11 13 15x 17 19 21x 23 25 27x 29 31 33x 35 37 39x
 * 3 5 7 9x 11 13 15xx 17 19 21x 23 25x 27x 29 31 33x 35x 37 39x
 * 3 5 7 9x 11 13 15xx 17 19 21xx 23 25x 27x 29 31 33x 35xx 37 39x
 */

static int get_first_idx(int idx, char *val, int max)
{
	while (idx < max) {
		if (test_bit(val, idx) == 1)
			return idx;
		idx++;
	}

	return idx;
}

static int idx_val(int idx)
{
	return ((idx + 1) << 1 ) + 1;
}

static void mask_idx(int idx, char *val, int max)
{
	int offset = idx_val(idx);

	idx += offset;
	if (idx >= max)
		return;
	while (idx < max) {
		clear_bit(val, idx);
		idx += offset;
	}
}

static void print_val(char *val, int max)
{
	int idx = 0;
	int count;

	/* always print 2 */
	printf("%5d", 2);
	count = 1;

	while (idx < max) {
		if (test_bit(val, idx)) {
			printf("%5d", idx_val(idx));
			if (count++ == 9) {
				putchar('\n');
				count = 0;
			}
		}
		idx++;
	}
	putchar('\n');
}

int main(void)
{
	char val[MAX_NUM];
	int idx = 0;
	int bit_num = MAX_NUM * 8;

	/* set values to true */
	memset(val, 0xff, sizeof(val));

	while (idx < bit_num) {
		/* find first value */
		idx = get_first_idx(idx, val, bit_num);

		/* mask multi of this value */
		mask_idx(idx, val, bit_num);
		idx++;
	}

	/* print results */
	print_val(val, bit_num);

	return 0;
}

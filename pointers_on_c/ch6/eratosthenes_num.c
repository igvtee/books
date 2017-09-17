#include <stdio.h>
#include <string.h>
#include "bit.h"

#define MAX_NUM (1000000/8)

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

static void count_num(char *val, int max)
{
	int idx = 0;
	int count = 1;

	while (idx < max) {
		if (test_bit(val, idx))
			count++;
		idx++;
		if (idx != 1 && (idx % 1000 == 0)) {
			printf("%10d %5d\n", idx, count);
			count = 0;
		}
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
	count_num(val, bit_num);

	return 0;
}

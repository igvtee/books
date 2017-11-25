/*
 * Compute the average age of family members. Each line of input is for one
 * family; it contains the ages of all family members.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buffer[512];

	/*
	 * Get the input one line at a time.
	 */
	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		char *bp;
		int members;
		long sum;
		long age;

		/*
		 * Decode the ages, one by one.
		 */
		sum = 0;
		members = 0;

		bp = buffer;
		while ((age = strtol(bp, &bp, 10)) > 0) {
			members += 1;
			sum += age;
		}

		if (members == 0)
			continue;

		/*
		 * Compute the average and print the results.
		 */
		printf("%5.2f: %s", (double)sum/members, buffer);

	}

	return 0;
}

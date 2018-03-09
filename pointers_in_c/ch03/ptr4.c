#include <stdio.h>

int main(int argc, char* argv[])
{
	int data[4] = {1,2,3,4};
	int *iptr1;
	int *iptr2;
	int val;
	iptr1 = &data[0];
	iptr2 = &data[1];
	val = iptr2 - iptr1;
	printf("Distance between the two addresses = %d\n", val);
	return 0;
}

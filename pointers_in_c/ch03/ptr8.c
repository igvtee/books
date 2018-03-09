#include <stdio.h>
int main(int argc, char* argv[])
{
	int arr[4] = {1,2,3,4};
	printf("Address of 0th index = %p\n", arr);
	printf("Address of 0th index = %p\n", &arr[0]);
	printf("Value at 0th index = %d\n", *arr);
	printf("Value at 0th index = %d\n", arr[0]);
	return 0;
}

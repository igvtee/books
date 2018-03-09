#include <stdio.h>

struct inner_node
{
	int in_a;
	int in_b;
};

struct node{
	int *a;
	int *b;
	struct inner_node* in_node;
};

int main()
{
	int *arrptr;
	int arr[10];
	arrptr = arr;
	printf("Size of pointer variable (struct node*) = %zu\n",sizeof(struct node*));
	printf("Size of pointer variable pointing to int array = %zu\n", sizeof(arrptr));
	return 0;
}

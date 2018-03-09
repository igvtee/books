#include <malloc.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	struct data
	{
		int i;
		char c1;
		int j;
		char c2;
		int k;
	};
	struct data *dsptr;
	printf("Size of structure data = %zu\n", sizeof(struct data));
	dsptr = (struct data*)malloc(sizeof(struct data));
	printf("Address of member int i = %p\n", &(dsptr->i));
	printf("Address of member char c1 = %p\n", &(dsptr->c1));
	printf("Address of member int j = %p\n", &(dsptr->j));
	printf("Address of member char c2 = %p\n", &(dsptr->c2));
	printf("Address of member int k = %p\n", &(dsptr->k));
	return 0;
}

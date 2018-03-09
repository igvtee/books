#include <stdio.h>
#include <malloc.h>
int main(int argc, char* argv[])
{
	struct data
	{
		int i;
		char c;
		int j;
	};
	struct data *dsptr;
	printf("Size of structure data = %zu\n", sizeof(struct data));
	dsptr = (struct data*)malloc(sizeof(struct data));
	printf("Address of member int i = %p\n", &(dsptr->i));
	printf("Address of member char c = %p\n", &(dsptr->c));
	printf("Address of member int j = %p\n", &(dsptr->j));
	return 0;
}

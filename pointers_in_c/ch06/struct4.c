#include <stdio.h>
int main(int argc, char * argv[])
{
	struct data
	{
		int i;
		int j;
		int k;
	};
	struct data v1;
	printf("Size of structure data = %zu\n", sizeof(struct data));
	return 0;
}

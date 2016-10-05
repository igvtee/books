#include <stdlib.h>

int main(void)
{
	int i;
	char* p = (char *)malloc(10);
	char* pt = p;

	for (i = 0;i < 10;i++)
	{
		p[i] = 'z';
	}
	free (p);
	free(pt);

	return 0;
}

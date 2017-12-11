#include <stdio.h>

void a(int i)
{
	if (i > 0)
		a(--i);
	else
		printf("i has reached zero\n");
	return;
}

int main(void)
{
	a(1);
	return 0;
}

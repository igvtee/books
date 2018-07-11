#include <stdio.h>

typedef struct
{
	char a;
	int b;
} ST_A;

int main(void)
{
	printf("sizeof(ST_A)=%ld\n",sizeof(ST_A));
}

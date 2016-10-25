#include <stdio.h>

int max__0(int a, int b)
{
	printf("max__0\n");
	return (a > b ? a : b);
}

int max__1(int a, int b)
{
	printf("max__1\n");
	return (a > b ? a : b);
}

int max__1_5(int a, int b)
{
	printf("max__1_5\n");
	return (a > b ? a : b);
}

int max__2(int a, int b, int c)
{
	int d = a > b ? a : b;
	printf("max__2\n");
	return (d > c ? d : c);
}

__asm__ (".symver max__0,max@");
__asm__ (".symver max__1,max@LIBMAX_1.0");
__asm__ (".symver max__1_5,max@LIBMAX_1.5");
__asm__ (".symver max__2,max@@LIBMAX_2.0");

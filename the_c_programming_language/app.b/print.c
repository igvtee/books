#include <stdio.h>

int main(void)
{
	printf("%%-20d:'%-20d'\n", 1);
	printf("%%+d:'%+d %+d'\n", 1, -1);
	printf("%% d:'% d % d'\n", 1, -1);
	printf("%%05d:'%05d'\n", 1);
	printf("%%#od:'%#od'\n", 1);
	printf("%%#xd %%#Xd:'%#xd %#Xd'\n", 1, 1);
	printf("%%#ef %%#Ef %%#ff %%#gf %%#Gf:'" \
	       "%#ef %#Ef %#ff %#gf %#Gf'\n",
	       -1.1, -1.1, -1.1, -1.1, -1.1);

	return 0;
}

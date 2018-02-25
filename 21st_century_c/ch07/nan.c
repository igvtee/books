#include <stdio.h>
#include <math.h>

void print_na(double in){
    char *cc = (char *)(&in);

    for (int i=0; i < sizeof(double); i++)
        printf("%02hhx ", cc[i]);
    putchar('\n');
}

int main()
{
	double x = NAN;
	double y = NAN;

	print_na(x);
	print_na(x);
	print_na(y);

	if (x == x)
		printf("NAN == NAN\n");
	else
		printf("NAN != NAN\n");
}

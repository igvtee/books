#include <stdio.h>
int main()
{
	char *strliteral = "ADD";
	strliteral[0] = 'B'; //Modifying value of 0th index, NOT ALLOWED,
	//program will generate segmentation fault
	strliteral++ ; //Allowed
	return 0;
}

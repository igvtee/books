void my_function_1(int fruit[2][3][5]) { ; }
void my_function_2(int fruit[][3][5]) { ; }
void my_function_3(int (*fruit)[3][5]) { ; }

int main(void)
{
	int apricot[2][3][5];
	int (*p)[3][5] = apricot;
	int (*q)[2][3][5] = &apricot;

	my_function_1(apricot);
	my_function_2(apricot);
	my_function_3(apricot);

	my_function_1(p);
	my_function_2(p);
	my_function_3(p);

	my_function_1(*q);
	my_function_2(*q);
	my_function_3(*q);

	return 0;
}

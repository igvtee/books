#include <stdio.h>

int main(void)
{
	int quantity, price;
	char department[128];

	scanf("%d %d", &quantity, &price);
	scanf("%127s", department);

	printf("quantity: %d\n" \
	       "price: %d\n" \
	       "department: %s\n",
	       quantity, price, department);

	return 0;
}

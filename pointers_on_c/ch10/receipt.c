#include <stdio.h>

#define PRODUCT_SIZE 20

typedef struct {
	char product[PRODUCT_SIZE];
	int quantity;
	float unit_price;
	float total_amount;
} Transaction;

void print_receipt(Transaction trans)
{
	printf("%s\n", trans.product);
	printf("%d @ %.2f total %.2f\n", trans.quantity,
			trans.unit_price, trans.total_amount);
}

void print_receipt2(register Transaction const *trans)
{
	printf("%s\n", trans->product);
	printf("%d @ %.2f total %.2f\n", trans->quantity,
			trans->unit_price, trans->total_amount);
}

Transaction compute_total_amount(Transaction trans)
{
	trans.total_amount = trans.quantity * trans.unit_price;
	return trans;
}

float compute_total_amount2(Transaction trans)
{
	return trans.quantity * trans.unit_price;
}

void compute_total_amount3(register Transaction *trans)
{
	trans->total_amount = trans->quantity * trans->unit_price;
}

int main(void)
{
	Transaction trans = {"keyboard", 3, 100, 300};

	print_receipt(trans);
	print_receipt2(&trans);

	trans = compute_total_amount(trans);
	trans.total_amount = compute_total_amount2(trans);
	compute_total_amount3(&trans);

	return 0;
}

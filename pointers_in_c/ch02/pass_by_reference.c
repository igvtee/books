struct data
{
	int x;
	int y;
};

void func(struct data* v1)
{
	struct data *v2 = v1;
}

int main()
{
	struct data var;
	var.x = 10;
	var.y = 20;
	func(&var);
	return 0;
}

struct a_tag {
	int array[20];
} x, y;

struct a_tag my_function()
{
	return y;
}

int main(void)
{
	x = my_function();
	x.array[3] = 38;

	return 0;
}

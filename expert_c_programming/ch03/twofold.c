struct s_tag {
	int a[100];
};
struct s_tag orange, lime, lemon;

struct s_tag twofold(struct s_tag s)
{
	int j;
	for (j = 0; j < 100; j++)
		s.a[j] *= 2;
	return s;
}

int main(void)
{
	int i;

	for (i = 0; i < 100; i++)
		lime.a[i] = 1;
	lemon = twofold(lime);
	orange = lemon; /* assign entire struct */

	return 0;
}

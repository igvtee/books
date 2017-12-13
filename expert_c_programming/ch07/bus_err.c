int main(void)
{
	union {
		char a[10];
		int i;
	} u;
	int *p = (int *)&(u.a[1]);
	*p = 17;

	return 0;
}

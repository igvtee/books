int f(int)
{
	return 0;
}

int main(void)
{
	int ans;

	/* same as " = f" */
	int (*pf)(int) = &f;

	/* these are the same */
	ans = f(25);
	ans = (*pf)(25);
	ans =pf(25);

	return 0;
}

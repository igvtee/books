int intcompare(const int *i, const int *j)
{
	return (*i = *j);
}

qsort(a, 10, sizeof(int),
		(int (*)(const void *, const void *)) intcompare);

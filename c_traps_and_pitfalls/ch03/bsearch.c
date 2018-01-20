int *bsearch(int *t, int n, int x)
{
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = (hi + lo) / 2;
		if (x < t[mid])
			hi = mid - 1;
		else if (x > t[mid])
			lo = mid + 1;
		else
			return t + mid;
	}
	return NULL;
}

int *bsearch(int *t, int n, int x)
{
	int *lo = t, *hi = t + n;
	while (lo < hi) {
		int *mid = lo + ((hi - lo) >> 1);
		if (x < *mid)
			hi = mid;
		else if (x > *mid)
			lo = mid + 1;
		else
			return mid;
	}
	return NULL;
}

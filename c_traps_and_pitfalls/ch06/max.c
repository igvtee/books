static int max_temp1, max_temp2;
#define max(p, q) \
	(max_temp1=(p), max_temp2=(q), \
	max_temp1>max_temp2 ? max_temp1 : max_temp2)

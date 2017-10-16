struct SIMPLE {
	int a;
	char b;
	float c;
};

struct COMPLEX {
	float f;
	int a[20];
	long *lp;
	struct SIMPLE s;
	struct SIMPLE sa[10];
	struct SIMPLE *sp;
};

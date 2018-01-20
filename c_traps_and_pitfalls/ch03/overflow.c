int a, b;
/* bug */
if (a + b < 0)
	complain();

/* fix */
if ((unsigned)a + (unsigned)b > INT_MAX)
	complain();

/* fix */
if (a > INT_MAX - b)
	complain();

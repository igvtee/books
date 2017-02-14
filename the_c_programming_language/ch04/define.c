#include <stdio.h>

#define forever for (;;)	/* infinite loop */
#define max(A, B)	((A) > (B) ? (A) : (B))
#define square(x)	x * x	/* WRONG */

#define dprint(expr)	printf(#expr " = %g\n", expr)
#define paste(front, back)	front ## back

/* conditional inclusion */
#if !defined(HDR)
#define HDR
/* contents of hdr.h go here */
#endif

#undef HDR
#if SYSTEM == SYSV
	#define	HDR	"sysv.h"
#elif SYSTEM == BSD
	#define	HDR	"bsd.h"
#elif SYSTEM == MSDOS
	#define	HDR	"msdos.h"
#else
	#define	HDR	"default.h"
#endif
//#include HDR

/* #ifndef HDR */
/* #ifdef HDR */

int main(void)
{
	int p, q, r, s, x;
	double z = 3.456;
	int name1 = 66;

	p = 1;
	q = 2;
	r = 3;
	s = 4;

	x = max(p+q, r+s);
	printf("%d\n", x);

	x = max(p++, q++);
	printf("%d\n", x);

	printf("%d\n", square(s+1));
	dprint(z/q);
	printf("%d\n", paste(name, 1));

	return 0;
}

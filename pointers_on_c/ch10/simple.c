#include <stdio.h>
#include "complex.h"

struct {
	int a;
	char b;
	float c;
} x;

struct {
	int a;
	char b;
	float c;
} y[20], *z;

typedef struct {
	int a;
	char b;
	float c;
} Simple;

int main(void)
{
	struct SIMPLE xx;
	struct SIMPLE yy[20], *zz;
	Simple xxxx;
	Simple yyy[20], *zzz;

	/* invalid */
	z = &x;

	/* ok */
	zz = &xx;

	return 0;
}

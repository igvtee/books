#include <stdio.h>
#include <math.h>	/* sqrt */

#define XMAX	300
#define YMAX	400
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x &&
		p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}

int main(void)
{
	struct point pt = { 320, 200 };
	double dist;
	struct rect screen, canon;
	struct point middle;
	struct point *pp;

	/* point */
	dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
	printf("x,y = %d,%d dist = %g\n", pt.x, pt.y, dist);

	/* screen */
	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(XMAX, YMAX);
	middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
			   (screen.pt1.y + screen.pt2.y)/2);
	printf("point(%d,%d) middle is (%d,%d)\n", XMAX, YMAX,
	       middle.x, middle.y);

	/* rect */
	screen.pt1 = pt;
	canon = canonrect(screen);

	printf("canon:(%d,%d),(%d,%d)\n", canon.pt1.x, canon.pt1.y,
	       canon.pt2.x, canon.pt2.y);
	printf("(%d,%d) is %sin canon\n", middle.x, middle.y,
	       ptinrect(middle, canon) ? "" : "not ");

	/* pointer */
	pp = &middle;
	printf("middle is (%d,%d)\n", (*pp).x, pp->y);

	return 0;
}

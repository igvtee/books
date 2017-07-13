#define cat(x,y) x ## y
#define xcat(x,y) cat(x,y)

xcat(xcat(1,2),3)

/*
 * xcat(xcat(1,2),3)
 * => cat(xcat(1,2),3)
 * => cat(cat(1,2),3)
 * => cat(12,3)
 * => 123
 */

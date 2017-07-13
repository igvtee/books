#define cat(x, y) x ## y

cat(var, 123)

/*
 * cat(cat(1,2),3)
 * => cat ( 1 , 2 )3
 * => ")3" is invalid token
 */

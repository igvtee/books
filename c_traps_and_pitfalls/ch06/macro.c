#define abs(x) (((x)>=0) ? (x) : -(x))

#define putc(x,p) \
	(--(p)->_cnt >= 0 ? (*(p)->_ptr++ = (x)) : _flsbuf(x,p))

#define toupper(c) \
	((c) >= 'a' && (c) <= 'z' ? (c) + ('A'-'a') : (c))
/* have problem */
toupper(*p++)

#define assert(e) \
	if (!e) assert_error(__FILE__, __LINE__)
/* have problem */
if (x > 0 && y > 0)
	assert(x > y);
else
	assert(y > x);

/* still have problem */
#define assert(e) \
	{if (!e) assert_error(__FILE__, __LINE__);}

#define assert(e) \
	((void)((e) || assert_error(__FILE__, __LINE__)))

#define T1 struct foo *
typedef struct foo *T2
T1 a, b;
T2 a, b;

/* have problem */
struct foo * a, b;


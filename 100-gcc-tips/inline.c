#if defined(__GNUC__)
#define FORCEDINLINE  __attribute__((always_inline))
#else
#define FORCEDINLINE
#endif

FORCEDINLINE int add(int a,int b)
{
	return a+b;
}

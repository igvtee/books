#if (GCC_VERSION > 4000)
#define DEBUG_FUNCTION __attribute__ ((__used__))
#define DEBUG_VARIABLE __attribute__ ((__used__))
#else
#define DEBUG_FUNCTION
#define DEBUG_VARIABLE
#endif

DEBUG_FUNCTION void
debug_bb (basic_block bb)
{
	dump_bb (bb, stderr, 0);
}

#include "cpu_type.h"

int cpu_type(void)
{
#if define(VAX)
	return CPU_VAX;
#elif define(M68000)
	return CPU_68000;
#elif define(M68020)
	return CPU_68020;
#elif define(I80386)
	return CPU_80386;
#elif define(X6809)
	return CPU_6809;
#elif define(X6502)
	return CPU_6502;
#elif define(U3B2)
	return CPU_3B2;
#else
	return CPU_UNKNOWN;
#endif
}

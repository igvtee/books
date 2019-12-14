#include <unistd.h>
#include <stdio.h>

#define PSYSCONF(name) printf(#name " %ld\n", sysconf(name))

/* /sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size */
int main(void)
{
	long cache_size;

	PSYSCONF(_SC_LEVEL1_ICACHE_SIZE);
	PSYSCONF(_SC_LEVEL1_ICACHE_ASSOC);
	PSYSCONF(_SC_LEVEL1_ICACHE_LINESIZE);
	PSYSCONF(_SC_LEVEL1_DCACHE_SIZE);
	PSYSCONF(_SC_LEVEL1_DCACHE_ASSOC);
	PSYSCONF(_SC_LEVEL1_DCACHE_LINESIZE);

	PSYSCONF(_SC_LEVEL2_CACHE_SIZE);
	PSYSCONF(_SC_LEVEL2_CACHE_ASSOC);
	PSYSCONF(_SC_LEVEL2_CACHE_LINESIZE);

	PSYSCONF(_SC_LEVEL3_CACHE_SIZE);
	PSYSCONF(_SC_LEVEL3_CACHE_ASSOC);
	PSYSCONF(_SC_LEVEL3_CACHE_LINESIZE);

	PSYSCONF(_SC_LEVEL4_CACHE_SIZE);
	PSYSCONF(_SC_LEVEL4_CACHE_ASSOC);
	PSYSCONF(_SC_LEVEL4_CACHE_LINESIZE);

	cache_size = sysconf(_SC_LEVEL1_ICACHE_SIZE) + \
		     sysconf(_SC_LEVEL1_DCACHE_SIZE) + \
		     sysconf(_SC_LEVEL2_CACHE_SIZE) + \
		     sysconf(_SC_LEVEL3_CACHE_SIZE) + \
		     sysconf(_SC_LEVEL4_CACHE_SIZE);

	printf("total cache size: %ld\n", cache_size);
}

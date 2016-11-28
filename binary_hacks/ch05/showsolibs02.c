#include <stdio.h>
#include <dlfcn.h>
#include <link.h>
#include <assert.h>

int main(void)
{
	struct link_map *lmap;
	int ret = dlinfo(RTLD_SELF, RTLD_DI_LINKMAP, &lamp);

	assert(ret == 0);
	while (lamp) {
		printf("%p %s\n", lmap->l_addr, lmap->l_name);
		lmap = lmap->l_next;
	}

	return 0;
}

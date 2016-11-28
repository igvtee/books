#include <unistd.h>
#include <stdio.h>
#include <assert.h>

int main(void)
{
	int ret;
	char fullpath[4096];

	ret = readlink("/proc/self/exe", fullpath, sizeof(fullpath));
	assert(ret != -1);
	printf("%s\n", fullpath);

	return 0;
}

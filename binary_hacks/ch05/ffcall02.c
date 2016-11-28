#include <avcall.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
	int ret;
	av_alist alist;
	void *dlh;
	void *fp;
	int i;

	if (argc < 2)
		return 1;

	dlh = dlopen(argv[0], RTLD_LAZY);
	fp = dlsym(dlh, argv[1]);

	av_start_int(alist, fp, &ret);

	for (i = 2; i < argc; i += 2) {
		/* string */
		if (argv[i][0] == 's') {
			av_ptr(alist, char *, argv[i+1]);
		}
		/* int */
		else if (argv[i][0] == 'i') {
			av_int(alist, atoi(argv[i+1]));
		}
	}

	av_call(alist);

	printf("\nRESULT: %d\n", ret);

	return 0;
}

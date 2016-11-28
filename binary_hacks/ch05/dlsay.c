#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>	// exit

int main(int argc, char *argv[])
{
	void *handle;
	char *(*msg)();
	char *error;

	handle = dlopen(argv[1], RTLD_LAZY);
	if (handle == NULL) {
		fprintf(stderr, "load error %s: %s\n", argv[1], dlerror());
		exit(1);
	}
	dlerror(); /* clear error */

	msg = (char *(*)()) dlsym(handle, argv[2]);
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "dlsym error %s: %s\n", argv[2], error);
		exit(1);
	}

	printf("%s\n", (*msg)(argc > 3 ? argv[3] : NULL));
	dlclose(handle);
	exit(0);
}

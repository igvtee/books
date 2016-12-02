#include <pthread.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdint.h>

#pragma weak __libc_stack_end
extern void * __libc_stack_end;

#ifdef __x86_64__
#define INITIAL_PROCESS_STACK_END ((char *)0xffff880000000000)
#else
#define INITIAL_PROCESS_STACK_END ((char *)0xc0000000U)
#endif
#define DEFAULT_FIXED_STACK_SIZE (2 * 1024 * 1024)

typedef int (*GETATTR_NP_FUNC)(pthread_t, pthread_attr_t *);
typedef int (*ATTR_GETSTACKBASE_FUNC)(pthread_attr_t *, void **);
typedef int (*ATTR_GETSTACKSIZE_FUNC)(pthread_attr_t *, size_t *);
typedef int (*ATTR_GETSTACK_FUNC)(pthread_attr_t *, void **, size_t *);

int get_linux_stack_info(void ** stackaddr, size_t * stacksize)
{
	char dummy;
	char *p = &dummy;
	char * initial_process_stack_end = INITIAL_PROCESS_STACK_END;
	size_t process_stack_size = 0;
	long pagesize = sysconf(_SC_PAGESIZE);
	struct rlimit rlim;

	getrlimit(RLIMIT_STACK, &rlim);
	process_stack_size = (size_t)rlim.rlim_cur;

	if (&__libc_stack_end && __libc_stack_end) {
		initial_process_stack_end = (char *)(
				((uintptr_t)__libc_stack_end + pagesize)
				& ~(pagesize - 1));
	}

	if (initial_process_stack_end - process_stack_size <= p &&
			p <= initial_process_stack_end) {
		/* process thread */
		*stackaddr = (void *)(initial_process_stack_end -
				process_stack_size);
		*stacksize = process_stack_size;

		return 0;
	} else {
		GETATTR_NP_FUNC getattr_np_func = (GETATTR_NP_FUNC)
			dlsym(NULL, "pthread_getattr_np");
		if (!getattr_np_func) {
			/* old thread, stack size 2 MB */
			*stackaddr = (void *)((size_t)p &
					(DEFAULT_FIXED_STACK_SIZE - 1));
			*stacksize = DEFAULT_FIXED_STACK_SIZE;
			return 0;
		} else {
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			if (!getattr_np_func(pthread_self(), &attr)) {
				ATTR_GETSTACK_FUNC attr_getstack_func =
					(ATTR_GETSTACK_FUNC)
					dlsym(NULL, "pthread_attr_getstack");
				ATTR_GETSTACKBASE_FUNC attr_getstackaddr_func =
					(ATTR_GETSTACKBASE_FUNC)
					dlsym(NULL, "pthread_attr_getstackaddr");
				ATTR_GETSTACKSIZE_FUNC attr_getstacksize_func =
					(ATTR_GETSTACKSIZE_FUNC)
					dlsym(NULL, "pthread_attr_getstacksize");

				if (attr_getstack_func) {
					int ret = attr_getstack_func(&attr,
							stackaddr, stacksize);
					pthread_attr_destroy(&attr);
					return ret;
				} else if (attr_getstackaddr_func &&
						attr_getstacksize_func) {
					int ret = attr_getstackaddr_func(&attr,
							stackaddr) ||
						attr_getstacksize_func(&attr,
								stacksize);
					pthread_attr_destroy(&attr);
					return ret;
				}
			}
			pthread_attr_destroy(&attr);
		}
	}
	return -1;
}

void * show_stack(void *arg)
{
	void * addr;
	size_t size;
	intptr_t ret;

	ret = get_linux_stack_info(&addr, &size);
	printf("thread stack addr: %p, size: %zd\n", addr, size);

	return (void *)ret;
}

int main(void)
{
	void * addr;
	size_t size;
	intptr_t *ret;
	pthread_t th;

	get_linux_stack_info(&addr, &size);
	printf("main stack addr: %p, size: %zd\n", addr, size);
	pthread_create(&th, NULL, show_stack, NULL);
	pthread_join(th, (void **)&ret);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/mman.h>
#include <unistd.h>
#include <assert.h>
#include <sys/resource.h>
#include <pthread.h>

#define ALT_STACK_SIZE (64 * 1024)
#define YELLOW_ZONE_PAGES (1)
#define USE_SETSTACK

/*
 *     high
 * +-------------+ <- stack_pointer + stack_size
 * |             |
 * +-------------+ <- yellow_zone_boundary
 * |   yellow    |
 * +-------------+ <- red_zone_boundary
 * |   red       |
 * +-------------+ <- stack_pointer
 *     low
 */

typedef struct {
	size_t stack_size;
	char * stack_pointer;
	char * red_zone_boundary;
	char * yellow_zone_boundary;
	sigjmp_buf return_point;
	size_t red_zone_size;
} ThreadInfo;

static pthread_key_t thread_info_key;
static struct sigaction newAct, oldAct;

/* user defined functions */
static void main_routine(void)
{
	main_routine();
}

/* red zone handler */
static void stackoverflow_routine(void)
{
	fprintf(stderr, "stack overflow error.\n");
	fflush(stderr);
}

/* yellow zone handler */
static void yellow_zone_hook(void)
{
	fprintf(stderr, "exceeded yellow zone.\n");
	fflush(stderr);
}

static int get_stack_info(void **stackaddr, size_t *stacksize)
{
	int ret = -1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	if (pthread_getattr_np(pthread_self(), &attr) == 0)
		ret = pthread_attr_getstack(&attr, stackaddr, stacksize);

	pthread_attr_destroy(&attr);

	return ret;
}

/* stack overflow core */
static int is_in_stack(const ThreadInfo *tinfo, char *pointer)
{
	return (tinfo->stack_pointer <= pointer) && (pointer <
			tinfo->stack_pointer + tinfo->stack_size);
}

static int is_in_red_zone(const ThreadInfo *tinfo, char *pointer)
{
	assert(tinfo->red_zone_boundary);
	return (tinfo->stack_pointer <= pointer) && (pointer <
			tinfo->red_zone_boundary);
}

static int is_in_yellow_zone(const ThreadInfo *tinfo, char *pointer)
{
	assert(tinfo->yellow_zone_boundary);
	return (tinfo->red_zone_boundary <= pointer) && (pointer <
			tinfo->yellow_zone_boundary);
}

#ifdef USE_SETSTACK
static void set_red_zone(ThreadInfo *tinfo)
{
	size_t pagesize = tinfo->red_zone_boundary - tinfo->stack_pointer;
	assert(pagesize > 0);
	mprotect(tinfo->stack_pointer, pagesize, PROT_NONE);
}
#endif

static void set_yellow_zone(ThreadInfo *tinfo)
{
	int pagesize = sysconf(_SC_PAGE_SIZE);
	assert(pagesize > 0);
	tinfo->yellow_zone_boundary = tinfo->red_zone_boundary + pagesize *
		YELLOW_ZONE_PAGES;
	mprotect(tinfo->red_zone_boundary, pagesize * YELLOW_ZONE_PAGES,
			PROT_NONE);
}

static void reset_yellow_zone(ThreadInfo *tinfo)
{
	size_t pagesize = tinfo->yellow_zone_boundary - tinfo->red_zone_boundary;

	if (mmap(tinfo->red_zone_boundary, pagesize, PROT_READ | PROT_WRITE,
				MAP_PRIVATE | MAP_ANONYMOUS, 0, 0) == 0) {
		perror("mmap failed");
		exit(1);
	}

	mprotect(tinfo->red_zone_boundary, pagesize, PROT_READ | PROT_WRITE);
	tinfo->yellow_zone_boundary = 0;
}

static void signal_handler(int sig, siginfo_t *sig_info, void *sig_data)
{
	if (sig == SIGSEGV) {
		ThreadInfo * tinfo = (ThreadInfo *)
			pthread_getspecific(thread_info_key);
		char *fault_address = (char *)sig_info->si_addr;

		printf("fault: %p, yellow: %p, red: %p, stack: %p\n",
				fault_address, tinfo->yellow_zone_boundary,
				tinfo->red_zone_boundary, tinfo->stack_pointer);
		if (is_in_stack(tinfo, fault_address)) {
			if (is_in_red_zone(tinfo, fault_address)) {
				fprintf(stderr, "exceeded red zone.\n");
				fflush(stderr);
				siglongjmp(tinfo->return_point, 1);
			} else if (is_in_yellow_zone(tinfo, fault_address)) {
				reset_yellow_zone(tinfo);
				yellow_zone_hook();
				return;
			} else {
			}
		} else {
			fprintf(stderr, "exceeded stack address.\n");
			fflush(stderr);
			siglongjmp(tinfo->return_point, 1);
		}
		/* oldAct.sa_sigaction(sig, sig_info, sig_data); */
	}
}

static void register_application_info(void)
{
	pthread_key_create(&thread_info_key, NULL);

	sigemptyset(&newAct.sa_mask);
	sigaddset(&newAct.sa_mask, SIGSEGV);
	newAct.sa_sigaction = signal_handler;
	newAct.sa_flags = SA_SIGINFO | SA_RESTART | SA_ONSTACK;

	sigaction(SIGSEGV, &newAct, &oldAct);
}

static void register_thread_info(ThreadInfo *tinfo)
{
	stack_t ss;

	pthread_setspecific(thread_info_key, tinfo);
	get_stack_info((void **)&tinfo->stack_pointer, &tinfo->stack_size);
	tinfo->red_zone_boundary = tinfo->stack_pointer + tinfo->red_zone_size;
	set_yellow_zone(tinfo);
#ifdef USE_SETSTACK
	set_red_zone(tinfo);
#endif

	ss.ss_sp = (char *)malloc(ALT_STACK_SIZE);
	ss.ss_size = ALT_STACK_SIZE;
	ss.ss_flags = 0;
	sigaltstack(&ss, NULL);
}

static void * thread_routine(void * p)
{
	ThreadInfo * tinfo = (ThreadInfo *)p;

	register_thread_info(tinfo);
	if (sigsetjmp(tinfo->return_point, 1) == 0) {
		main_routine();
	} else {
		stackoverflow_routine();
	}
	free(tinfo);
	return NULL;
}

int main(int argc, char **argv)
{
	register_application_info();

	if (argc == 2) {
		size_t stacksize = atoi(argv[1]) * 1024 * 1024;
		void * stackaddr;
		pthread_t pid0;
		ThreadInfo *tinfo = (ThreadInfo *)calloc(1, sizeof(ThreadInfo));

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_getguardsize(&attr, &tinfo->red_zone_size);
#ifdef USE_SETSTACK
		if (posix_memalign(&stackaddr, sysconf(_SC_PAGESIZE), stacksize))
			printf("posiz_memalign error\n");
		if (pthread_attr_setstack(&attr, stackaddr, stacksize))
			printf("setstack error\n");
/*
		if (pthread_attr_setguardsize(&attr, tinfo->red_zone_size))
			printf("setguardsize error\n");
*/
#else
		//pthread_attr_setstackaddr(&attr, (void *)stacksize);
#endif
		if (pthread_create(&pid0, &attr, thread_routine, tinfo)) {
			printf("error\n");
			return 1;
		}
		pthread_join(pid0, NULL);
	} else {
		printf("Usage: %s stacksize(mb)\n", argv[0]);
	}

	return 0;
}

#include <stdio.h>
#include <string.h>
#include <uloop.h>

void f1_cb(struct uloop_timeout *t)
{
	int msec = 1000;
	printf("%s: %d\n", __func__, msec);
	uloop_timeout_cancel(t);
}

void f2_cb(struct uloop_timeout *t)
{
	int msec = 2000;
	printf("%s: %d\n", __func__, msec);
	uloop_timeout_set(t, msec);
}

void f3_cb(struct uloop_timeout *t)
{
	int msec = 3000;
	printf("%s: %d\n", __func__, msec);
	uloop_timeout_set(t, msec);
}

void f4_cb(struct uloop_timeout *t __attribute__((unused)))
{
	printf("%s: cancel uloop\n", __func__);
	uloop_end();
}

int main(void)
{
	struct uloop_timeout f1, f2, f3, f4;

	memset(&f1, 0, sizeof(f1));
	f1.cb = f1_cb;
	memset(&f2, 0, sizeof(f2));
	f2.cb = f2_cb;
	memset(&f3, 0, sizeof(f3));
	f3.cb = f3_cb;
	memset(&f4, 0, sizeof(f4));
	f4.cb = f4_cb;

	uloop_init();
	uloop_timeout_set(&f1, 1000);
	uloop_timeout_set(&f2, 2000);
	uloop_timeout_set(&f3, 3000);
	uloop_timeout_set(&f4, 10000);
	printf("f1 remaining time: %d\n", uloop_timeout_remaining(&f1));
	uloop_run();
	uloop_done();

	return 0;
}

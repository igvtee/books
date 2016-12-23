#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long clockcount_pentium(void)
{
	unsigned long long ret;
	__asm__ volatile ("rdtsc" : "=A" (ret));
	return ret;
}

unsigned long long clockcount_amd64(void)
{
	unsigned int eax, edx;
	__asm__ volatile ("rdtsc" : "=a" (eax), "=d" (edx));
	return eax | (unsigned long long)edx << 32;
}

int main(void)
{
	int ret;
	struct timeval tv1, tv2;
	unsigned long long c1, c2;
	double t, speed, uptime;
	unsigned long long (*clockcount)(void);

	clockcount = clockcount_amd64;
	c1 = clockcount();
	ret = gettimeofday(&tv1, NULL);
	if (ret == -1) {
		perror("gettimeofday");
		exit(1);
	}
	for (;;) {
		sleep(1);
		c2 = clockcount();
		ret = gettimeofday(&tv2, NULL);
		if (ret == -1) {
			perror("gettimeofday");
			exit(1);
		}
		t = tv2.tv_sec - tv1.tv_sec + (tv2.tv_usec - tv1.tv_usec) * 1e-6;
		speed = (c2 - c1) / t;
		uptime = c2 / speed;
		printf("0x%llx %lf[Hz] %lf[sec]\n", c2, speed, uptime);
	}
	return 0;
}

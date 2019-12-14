/* ***********************************************
MYID	: Chen Fan
LANG	: C
PROG	:
 ************************************************ */

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>

#define KB (1024/4)
#define MB (1024 * KB)
#define SIZE (128 * MB)

double getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	//获取秒
	double sec = (double)tv.tv_sec;
	//获取微秒
	double usec = (double)tv.tv_usec;
	//返回微秒数
	return sec * 1000000 + usec;
}

void cache_line_test(int *array)
{
	for (int stride=1;stride<64*KB;stride*=2)
	{
		double begin_time = getTime();
		for (int i=0;i<SIZE;i+=stride)
		{
			array[i] *= 10;
		}
		double end_time = getTime();
		printf("Stride: %5d,  Line Size: %5d Bytes,  Average Cost: %10lf us\n",
		       stride, stride*4, (end_time - begin_time) / (SIZE/stride));
	}
}

void cache_block_test(int *array)
{
	for (int num=KB;num<MB;num*=2)
	{
		int len = num-1;
		int tot = SIZE-1;
		double begin_time = getTime();
		for (int i=0;i<tot;i++)
		{
			array[(i*16) & len] *= 10;
		}
		double end_time = getTime();
		printf("Num: %8d,  Size: %8d KB,  cost %10lf us\n", num,
		       num*4/1024, end_time - begin_time);
	}
	for (int num=MB;num<16*MB;num+=MB)
	{
		int len = num-1;
		int tot = SIZE-1;
		double begin_time = getTime();
		for (int i=0;i<tot;i++)
		{
			array[(i*16) & len] *= 10;
		}
		double end_time = getTime();
		printf("Num: %8d,  Size: %8d MB,  cost %10lf us\n", num,
		       num*4/1024/1024, end_time - begin_time);
	}
}

int main(void)
{
	int *array = malloc(sizeof(int) * SIZE);
	if (!array)
		printf("malloc size %d error\n", SIZE);
	for (int i=0;i<SIZE;i++) array[i] = i;

	cache_line_test(array);
	cache_block_test(array);

	return 0;
}

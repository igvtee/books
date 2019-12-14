/* compile time */
#define barrier() __asm__ __volatile__ ("" ::: "memory")

/* runtime hardware barrier
 * on x86 will generate mfence
 *  __sync_synchronize()
 */

void loop_without_barrier(void)
{
	int i, N = 100;
	int a[N];

	for (i = 0; i < N; ++i) {
		a[i]++;
	}
}

void loop_with_barrier(void)
{
	int i, N = 100;
	int a[N];

	for (i = 0; i < N; ++i) {
		a[i]++;
		barrier();
	}
}

int main(void)
{
	loop_with_barrier();
	loop_without_barrier();
	__sync_synchronize();
}

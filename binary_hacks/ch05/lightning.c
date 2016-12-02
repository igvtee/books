#include <stdio.h>
#include <lightning.h>

typedef int (*pifi)(int);
static jit_insn buf[1024];

pifi curry(int (*fp)(int, int), int a)
{
	pifi code = (pifi)(jit_set_ip(buf).iptr);
	int i;

	jit_prolog(1);
	i = jit_arg_ui();
	jit_getarg_ui(JIT_V0, i);
	jit_movi_ui(JIT_V1, a);
	jit_prepare(2);
	jit_pusharg_ui(JIT_V1);
	jit_pusharg_ui(JIT_V0);
	jit_finish(fp);
	jit_retval(JIT_RET);
	jit_ret();
	jit_flush_code(buf, jit_get_ip().ptr);

	return code
}

int add(int x, int y)
{
	return (x + y);
}

int main(void)
{
	pifi c;
	c = curry(add, 100);
	printf("%d\n", c(10));
}

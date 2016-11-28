#include <ffi.h>
#include <stdio.h>

char nth(const char *str, int i)
{
	return str[i - 1];
}

int main(void)
{
	int n = 5;
	const char *msg = "binary";

	ffi_cif cif;
	int arg_num;
	ffi_type *arg_types[2];
	void *arg_values[2];
	ffi_arg ret;
	ffi_type *ret_type;

	printf("NORMAL: %c\n", nth(msg, n));

	ret_type = &ffi_type_schar;
	arg_num = 2;
	arg_types[0] = &ffi_type_pointer;
	arg_values[0] = &msg;
	arg_types[1] = &ffi_type_sint;
	arg_values[1] = &n;

	ffi_prep_cif(&cif, FFI_DEFAULT_ABI, arg_num, ret_type, arg_types);
	ffi_call(&cif, FFI_FN(nth), &ret, arg_values);

	printf("LIBFFI: %c\n", (char)ret);

	return 0;
}

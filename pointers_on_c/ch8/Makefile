program := array message matrix matrix2 matrix_func keyword \
	   keyword2 keyword3 ints palindrome ab array1  array2 \
	   char_value single_tax identity_matrix identity_matrix2 \
	   matrix_multiply array_offset array_offset2 queen
assemble := try1.s try2.s try3.s try4.s try5.s

.PHONY: all clean
all: $(program) $(assemble)

%.s: %.c
	$(CC) -S $^

clean:
	@rm -f $(program) *.o *.s

ab: ab.o ab_main.o

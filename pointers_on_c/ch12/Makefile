program := count dll_ins6 sll_reverse sll_remove dll_remove indextable

.PHONY: all clean
all: $(program)

count sll_reverse sll_remove: insert3.o

sll_reverse sll_remove: sll_print.o

dll_remove: dll_ins4.o

clean:
	@rm -f $(program) *.o *.s

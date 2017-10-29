VPATH = ../ch12
program := xyz point count sll_callback sort do_args

.PHONY: all clean
all: $(program)

sll_callback: CFLAGS+=-I../ch12
sll_callback: insert3.o

clean:
	@rm -f $(program) *.o *.s

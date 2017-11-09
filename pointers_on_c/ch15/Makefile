program := istty short_fgets_size sprintf_max perror_list \
	   printf_float float copy1 copy2 copy3 copy4 ages \
	   hexdump fgrep sum

.PHONY: all clean
all: $(program)

float: CFLAGS+=-lm

clean:
	@rm -f $(program) *.o *.s

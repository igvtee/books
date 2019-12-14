CFLAGS += -Wall

program := checkcpu barrier.s cache_line_size cache_line_size2

.PHONY: all clean
all: $(program)

clean:
	@rm -f $(program)

barrier.s: barrier.c
	cc -S -O3 -c barrier.c

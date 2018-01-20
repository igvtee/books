CFLAGS += -Wall

program := scanf long_int sqrt

.PHONY: all clean
all: $(program)

long_int: long.o int.o
	$(CC) -o $@ $^

sqrt: CFLAGS += -lm

clean:
	@rm -f $(program)

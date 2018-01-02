program := list add.s system issigned

.PHONY: all clean
all: $(program)

add.o: add.c
	$(CC) -c -g $^

add.s: add.o
	objdump -Sl $^ > $@

clean:
	@rm -f $(program) *.o *.s

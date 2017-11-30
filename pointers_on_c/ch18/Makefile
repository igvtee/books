program :=
assemble := runtime.lst no-ret.s

.PHONY: all clean
all: $(program) $(assemble)

%.lst: %.c
	$(CC) -c -g -Wa,-a,-ad runtime.c > $@

%.s: %.c
	$(CC) -S $^

clean:
	@rm -f $(program) $(assemble) *.o

CFLAGS=-g

export LC_MESSAGES=C
EXECS = bench cachemiss debugregs breakpoint debugged
LIBS =
TEMPS = gmon.out

all: $(EXECS) $(LIBS)

%.so: %.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $<

bench: bench.c
	$(CC) $(CFLAGS) -O0 -pg -o $@ $^

debugregs: debugregs.c debugregsmain.c
	$(CC) $(CFLAGS) -m32 -o $@ $^

.PHONY:clean usage
clean:
	rm -f $(EXECS) $(LIBS) $(TEMPS)

usage:
	@echo "   === example usage ==="

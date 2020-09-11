EXECS =
LIBS = mylib.so
TEMPS =
CFLAGS = -llua

all: $(EXECS) $(LIBS)

%.so: %.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $<

mylib.so: counter.o map.o split.o
	$(CC) $(CFLAGS) -shared -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

.PHONY:clean usage
clean:
	rm -f $(EXECS) $(LIBS) $(TEMPS) *.o

usage:
	@echo "   === example usage ==="

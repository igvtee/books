MYLDFLAGS=-Wl,-rpath,'$$ORIGIN' -Wl,-rpath-link,'./'

program := main test test1

lib := libfruit.so libfruit_s.a

.PHONY: all clean
all: $(program) $(lib)

libfruit.so: tomato.c
	$(CC) -fPIC -shared -o $@ $<

libfruit_s.a: tomato.o
	$(AR) rcs $@ $^

main: main.c
	$(CC) -Wl,-M $^ -o $@ > main.linker.map

test: libfruit.so
	$(CC) $(MYLDFLAGS) $@.c -o $@ -L. -lfruit

test1: libfruit_s.a
	# $(CC) -L. test.c -lfruit_s -o $@
	-$(CC) -L. -lfruit_s test.c -o $@

clean:
	@rm -f $(program) $(lib) *.o main.linker.map

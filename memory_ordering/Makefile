PROGRAMS := ordering
ASSEMBLY := foo_O0.s foo_O2.s foo_barrier.s dosomestuff.s bar.s
OBJECTS =
CFLAGS =
LDFLAGS =
VPATH =

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS) $(ASSEMBLY)

foo_O0.s: foo.c
	$(CC) -S -fverbose-asm -O0 -o $@ $^

foo_O2.s: foo.c
	$(CC) -S -fverbose-asm -O2 -o $@ $^

foo_barrier.s: foo_barrier.c
	$(CC) -S -fverbose-asm -O2 -o $@ $^

%.s: %.c
	$(CC) -S -fverbose-asm -O2 -o $@ $^

ordering: ordering.cpp
	$(CXX) -O2 -o $@ $^ -lpthread

clean:
	@rm -f $(PROGRAMS) *.o *.s

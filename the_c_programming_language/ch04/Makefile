CC = gcc
CFLAGS =
INCLUDES =
LDFLAGS =
LIBS =
PROGS = $(patsubst %.c,%,$(wildcard exercise*.c)) \
	return grep atof calculator calc printd qsort \
	define
PROGS_LIBM = exercise4-03 exercise4-04 exercise4-05

all: $(PROGS)

$(PROGS_LIBM): CFLAGS += -lm

calc: main.o getop.o getch.o stack.o calc.h
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

exercise4-11: main.o exercise4-11.o getch.o stack.o calc.h
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean
clean:
	rm -f $(PROGS) *.o *.so

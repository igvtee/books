CC = gcc
CFLAGS = -Wall -g
INCLUDES =
LDFLAGS =
LIBS =
PROGS = $(patsubst %.c,%,$(wildcard exercise*.c)) \
	copy getchar01 getchar02 cp memory
PROGS_LIBM = 
PROGS_NOBUILDIN = memory exercise8-07

all: $(PROGS)

$(PROGS_LIBM): CFLAGS += -lm
$(PROGS_NOBUILDIN): CFLAGS += -fno-builtin

cp: cp.o error.o

exercise8-01: exercise8-01.o error.o

exercise8-02: exercise8-02 stdio.o

exercise8-03: exercise8-03.o fopen.o stdio.o fillbuf.o

exercise8-04: exercise8-04.o fopen.o stdio.o fillbuf.o

memory: memory.o malloc.o

exercise8-07: memory.o exercise8-07

.PHONY: clean exercise8-05 exercise8-06 exercise8-08
clean:
	rm -f $(PROGS) *.o *.so

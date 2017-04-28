CC = gcc
CFLAGS = -Wall -g
INCLUDES =
LDFLAGS =
LIBS =
PROGS = $(patsubst %.c,%,$(wildcard exercise*.c)) \
	lower printf minprintf calculator sscanf cat cat2
PROGS_LIBM = 

all: $(PROGS)

$(PROGS_LIBM): CFLAGS += -lm

sscanf: sscanf.o ../ch05/getline.o

exercise7-05.o: CFLAGS += -I../ch04

exercise7-05: ../ch04/main.o exercise7-05.o ../ch04/getch.o ../ch04/stack.o ../ch04/calc.h
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean exercise7-09
clean:
	rm -f $(PROGS) *.o *.so

CC = gcc
CFLAGS = -Wall -g
INCLUDES =
LDFLAGS =
LIBS =
PROGS = $(patsubst %.c,%,$(wildcard exercise*.c)) \
	point pointer keycount01 keycount02 holes wordcount typedef union bitfields
PROGS_LIBM = point

all: $(PROGS)

$(PROGS_LIBM): CFLAGS += -lm

keycount01: keycount01.o getword.o ../ch04/getch.o

exercise6-01: exercise6-01.o keycount01.o ../ch04/getch.o

keycount02: keycount02.o getword.o ../ch04/getch.o

wordcount: wordcount.o tnode.o talloc.o getword.o ../ch04/getch.o

exercise6-02: exercise6-02.o talloc.o getword.o ../ch04/getch.o

exercise6-03: exercise6-03.o talloc.o ../ch04/getch.o

exercise6-04: exercise6-04.o tnode.o talloc.o getword.o ../ch04/getch.o

exercise6-06: exercise6-06.o exercise6-05.o nlist.o talloc.o ../ch04/getch.o ../ch04/ungets.o

.PHONY: clean exercise6-05
clean:
	rm -f $(PROGS) *.o *.so

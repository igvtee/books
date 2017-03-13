CC = gcc
CFLAGS = -Wall -g
INCLUDES =
LDFLAGS =
LIBS =
PROGS = $(patsubst %.c,%,$(wildcard exercise*.c)) \
	pointer swap getint strlen01 strlen02 intlen ptrdiff sortline \
	monthday echo01 echo02 echo03 find01 find02 sort dcl undcl
PROGS_LIBM = exercise5-10

all: $(PROGS)

$(PROGS_LIBM): CFLAGS += -lm

getint: getint.o ../ch04/getch.o

exercise5-01: exercise5-01.o ../ch04/getch.o

exercise5-02: exercise5-02.o ../ch04/getch.o

exercise5-06: exercise5-06.o ../ch04/getch.o

sortline: sortline.o readlines01.o qsort01.o alloc.o strcpy.o getline.o

exercise5-07: exercise5-07.o qsort01.o strcpy.o getline.o

find01: find01.o getline.o

find02: find02.o getline.o

exercise5-10: exercise5-10.o ../ch04/getop.o ../ch04/getch.o ../ch04/stack.o ../ch04/ungets.o

exercise5-11-1: exercise5-11-1.o settab.o tabpos.o

exercise5-11-2: exercise5-11-2.o settab.o tabpos.o

exercise5-12: exercise5-12.o esettab.o tabpos.o

exercise5-13: exercise5-13.o getline.o error.o

sort: sort.o qsort02.o numcmp01.o readlines01.o alloc.o strcpy.o getline.o strcmp.o

exercise5-14: exercise5-14.o qsort02.o numcmp01.o readlines02.o alloc.o strcpy.o getline.o strcmp.o

exercise5-15: exercise5-15.o qsort02.o numcmp01.o readlines02.o alloc.o strcpy.o getline.o strcmp.o

exercise5-16: exercise5-16.o qsort02.o numcmp01.o readlines02.o alloc.o strcpy.o getline.o strcmp.o

exercise5-17: exercise5-17.o qsort02.o numcmp02.o readlines02.o alloc.o strcpy.o getline.o substr.o error.o

dcl: dcl.o gettoken01.o ../ch04/getch.o

undcl: undcl.o gettoken01.o ../ch04/getch.o

exercise5-18: exercise5-18.o gettoken02.o ../ch04/getch.o

exercise5-19: exercise5-19.o gettoken02.o ../ch04/getch.o

exercise5-20: exercise5-20.o gettoken02.o ../ch04/getch.o

.PHONY: clean
clean:
	rm -f $(PROGS) *.o *.so

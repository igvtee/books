CC = gcc
CFLAGS = -Wall -g
INCLUDES =
LDFLAGS =
LIBS =
PROGS = char wchar one_complement sizeof relational comma
PROGS_LIBM = 
PROGS_NOBUILDIN =

all: $(PROGS)

$(PROGS_LIBM): CFLAGS += -lm
$(PROGS_NOBUILDIN): CFLAGS += -fno-builtin

.PHONY:
clean:
	rm -f $(PROGS) *.o *.so

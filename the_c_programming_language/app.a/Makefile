CC = gcc
CFLAGS = -Wall -g
INCLUDES =
LDFLAGS =
LIBS =
PROGS = char wchar one_complement sizeof relational comma bitfield compound \
	trigraph predefine
PREPROCESS = tempfile.i cat.i xcat.i
PROGS_LIBM = 
PROGS_NOBUILDIN =

all: $(PROGS) $(PREPROCESS)

$(PROGS_LIBM): CFLAGS += -lm
$(PROGS_NOBUILDIN): CFLAGS += -fno-builtin

trigraph: CPPFLAGS += -trigraphs

%.i: %.c
	$(CC) -E $^ -o $@

.PHONY:
clean:
	rm -f $(PROGS) *.o *.so

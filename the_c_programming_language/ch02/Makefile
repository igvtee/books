CFLAGS=
OBJS=
LIBS=
EXECS= $(patsubst %.c,%,$(wildcard exercise*.c)) \
	constants leapyear conversions

all: $(OBJS) $(LIBS) $(EXECS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(LIBS) $(EXECS) *.o *.so

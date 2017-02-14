CFLAGS=
OBJS=
LIBS=
EXECS= $(patsubst %.c,%,$(wildcard exercise*.c)) \
	array atoi shellsort reverse itoa trim

all: $(OBJS) $(LIBS) $(EXECS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(LIBS) $(EXECS) *.o *.so

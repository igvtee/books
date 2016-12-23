CFLAGS=-g

export LC_MESSAGES=C
EXECS = clockcount floatbit float floatinf floatexc
LIBS =
TEMPS =

all: $(EXECS) $(LIBS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.so: %.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $<

floatexc: floatexc.c
	$(CC) $(CFLAGS) -lm -o $@ $^

.PHONY:clean usage
clean:
	rm -f $(EXECS) $(LIBS) $(TEMPS)

usage:
	@echo "   === example usage ==="

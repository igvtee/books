EXECS = lua_mini stackdump
LIBS =
TEMPS =
CFLAGS = -llua

all: $(EXECS) $(LIBS)

%.so: %.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $<

floatexc: floatexc.c
	$(CC) $(CFLAGS) -lm -o $@ $^

.PHONY:clean usage
clean:
	rm -f $(EXECS) $(LIBS) $(TEMPS)

usage:
	@echo "   === example usage ==="

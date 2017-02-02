EXECS = lua_mini
LIBS =
TEMPS =
CFLAGS = -llua

all: $(EXECS) $(LIBS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.so: %.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $<

lua_mini: lua_mini.c
	$(CC) $(CFLAGS) -lm -o $@ $^

.PHONY:clean usage
clean:
	rm -f $(EXECS) $(LIBS) $(TEMPS)

usage:
	@echo "   === example usage ==="

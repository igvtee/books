EXECS = lua_mini
LIBS = mylib.so
TEMPS =
CFLAGS = -llua

all: $(EXECS) $(LIBS)

%.so: %.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $<

lua_mini: lua_mini.c $(LIBS)
	$(CC) $(CFLAGS) -lm -o $@ $^

.PHONY:clean usage
clean:
	rm -f $(EXECS) $(LIBS) $(TEMPS)

usage:
	@echo "   === example usage ==="

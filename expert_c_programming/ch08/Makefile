program := char_size file stty kbhit curses printf have_fun \
	mixtype asynio cdecl

.PHONY: all clean
all: $(program)

file: file1.o file2.o
	$(CC) $^ -o $@

curses: LDFLAGS:=-lcurses

clean:
	@rm -f $(program) *.o

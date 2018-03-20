PROGRAMS := regex mmap
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS =
VPATH = ../ch10/

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS)

regex: CFLAGS += -Dtest_regexes
regex mmap: CFLAGS += -I../ch10/

clean:
	@rm -f $(PROGRAMS) *.o

PROGRAMS := dynamic intptr
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS = 

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS)

dynamic: LDLIBS = -lm -ldl -lreadline

clean:
	@rm -f $(PROGRAMS) *.o

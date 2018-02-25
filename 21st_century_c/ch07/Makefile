PROGRAMS := hello divide divide2 cast noreturn floatfail stddev \
	    stddev_bugged uint strtod nan na
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS = 

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS)

clean:
	@rm -f $(PROGRAMS) *.o

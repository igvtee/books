PROGRAMS := add test
OBJECTS =
ASSEMBLE := add.s
CFLAGS = -g -Wall -m32
LDFLAGS =

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS) $(ASSEMBLE)

%.s: %.c
	$(CC) -S -fverbose-asm -m32 $^

clean:
	@rm -f $(PROGRAMS) $(ASSEMBLE)

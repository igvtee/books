PROGRAMS := fptr1 fptr2 fptr3 fptr4
OBJECTS =
ASSEMBLE := call1.s call2.s
CFLAGS = -g -Wall
LDFLAGS =

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS) $(ASSEMBLE)

%.s: %.c
	$(CC) -S -fverbose-asm -m32 $^

clean:
	@rm -f $(PROGRAMS) $(ASSEMBLE)

PROGRAMS := fileprog1 fileprog2 fileprog3 fileprog4 fileprog5 fileprog6 \
	fileprog7 fileprog8 fileprog9 fileprog10 fileprog11 fileprog12 \
	fileprog13
OBJECTS =
ASSEMBLE :=
CFLAGS = -g -Wall
LDFLAGS =

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS) $(ASSEMBLE)

%.s: %.c
	$(CC) -S -fverbose-asm -m32 $^

clean:
	@rm -f $(PROGRAMS) $(ASSEMBLE)

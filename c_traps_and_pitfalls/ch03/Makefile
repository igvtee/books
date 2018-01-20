CFLAGS += -Wall

program := loop

loop: CFLAGS += -fno-stack-protector -m32

.PHONY: all clean
all: $(program)

clean:
	@rm -f $(program)

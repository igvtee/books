CFLAGS += -O2
CFLAGS += -Wall -Wextra -Wpedantic
#CFLAGS += -Werror -Wshadow

program := lp64 arch intptr align align_32 align_pack sign_ext1 sign_ext2

.PHONY: all clean
all: $(program)

align_32: align.c
	$(CC) $(CFLAGS) -m32 $^ -o $@

clean:
	@rm -f $(program)

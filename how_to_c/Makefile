CFLAGS += -O2
CFLAGS += -Wall -Wextra -Wpedantic
#CFLAGS += -Werror -Wshadow
CFLAGS += -flto

program := declaration_anywhere.o loop.o pragma_once static_init zero_struct \
	variable_array return_type.o

.PHONY: all clean
all: $(program)

clean:
	@rm -f $(program)

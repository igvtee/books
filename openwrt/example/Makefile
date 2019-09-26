CFLAGS += -Wall -Wextra -I../libubox -g3
LDFLAGS = -L../libubox -lubox -Wl,-rpath,../libubox

program := list safe_list avl vlist kvlist utils

.PHONY: all clean
all: $(program)

clean:
	@rm -f $(program)

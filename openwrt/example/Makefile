CFLAGS += -Wall -Wextra -I../libubox
LDFLAGS = -L../libubox -lubox -Wl,-rpath,../libubox

program := list safe_list

.PHONY: all clean
all: $(program)

clean:
	@rm -f $(program)

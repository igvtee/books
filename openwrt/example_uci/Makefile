CFLAGS += -Wall -Wextra -I../uci -g3
LDFLAGS = -L../uci -luci -Wl,-rpath,../uci

program := load_config save_config

.PHONY: all clean
all: $(program)

clean:
	@rm -f $(program)

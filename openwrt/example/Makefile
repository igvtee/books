CFLAGS += -Wall -Wextra -I../libubox -g3
LDFLAGS = -L../libubox -lubox -Wl,-rpath,../libubox

program := list safe_list avl vlist kvlist utils blob blobmsg usock_tcpserv \
	usock_tcpcli uloop_timer uloop_process uloop_fd

.PHONY: all clean
all: $(program)

blobmsg: CFLAGS += -lblobmsg_json

clean:
	@rm -f $(program)

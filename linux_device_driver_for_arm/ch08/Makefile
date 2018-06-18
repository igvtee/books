ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m := globalfifo.o globalfifo_poll.o

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else
CROSS_PROGS := gfifo_select gfifo_epoll
CFLAGS = -g -Wall -O3

include ../kernel_env.mk
endif

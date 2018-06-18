ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m := globalfifo_sigio.o

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else
CROSS_PROGS := gfifo_sigio
HOST_PROGS := signal signal_sigio aior
CFLAGS = -g -Wall -O3
LDFLAGS =

aior: LDFLAGS += -laio

include ../kernel_env.mk
endif

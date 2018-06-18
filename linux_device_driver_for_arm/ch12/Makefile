ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m := globalfifo_platform.o globalfifo_misc.o globalfifo_device.o

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else
CROSS_PROGS := 
CFLAGS = -g -Wall -O3
LDFLAGS =

include ../kernel_env.mk
endif

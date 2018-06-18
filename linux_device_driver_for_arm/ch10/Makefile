ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m := second.o

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else
CROSS_PROGS := second_test
CFLAGS = -g -Wall -O3
LDFLAGS =

include ../kernel_env.mk
endif

ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m := proc.o

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else
CROSS_PROGS :=
HOST_PROGS := example
CFLAGS = -g -Wall -O3
LDFLAGS =

include ../kernel_env.mk
endif

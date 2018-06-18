ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m :=

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else
HOST_PROGS := mallopt
CFLAGS = -g -Wall -O3
LDFLAGS =

include ../kernel_env.mk
endif

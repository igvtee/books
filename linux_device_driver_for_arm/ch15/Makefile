ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m :=

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else
CROSS_PROGS := i2c_read i2c_ioctl
CFLAGS = -g -Wall -O3
LDFLAGS =

include ../kernel_env.mk
endif

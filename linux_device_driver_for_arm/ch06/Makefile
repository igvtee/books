ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m := globalmem.o multi_globalmem.o

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else

include ../kernel_env.mk
endif

ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m := hello.o book.o export_symbol.o

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else

include ../kernel_env.mk
endif

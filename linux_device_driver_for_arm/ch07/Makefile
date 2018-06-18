ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m := globalmem_mutex.o

# Specify flags for the module compilation.
EXTRA_CFLAGS = -g -O0
else
ASSEMBLE := barrier.s

%.s: %.c
	$(CC) -S -fverbose-asm -O2 $^

include ../kernel_env.mk
endif

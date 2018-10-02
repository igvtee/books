
# To build modules outside of the kernel tree, we run "make"
# in the kernel source tree; the Makefile these then includes this
# Makefile once again.
# This conditional selects whether we are being included from the
# kernel Makefile or not.

ifneq ($(KERNELRELEASE),)
# Kernel modules
# called from kernel build system: just declare what our modules are
#obj-m := hello.o hellop.o seq.o jit.o jiq.o sleepy.o complete.o \
#         silly.o faulty.o kdatasize.o kdataalign.o
obj-m := hello.o sequence.o faulty.o complete.o counter.o test_slub.o \
	sleepy.o jit.o jiq.o

# Specify flags for the module compilation.
EXTRA_CFLAGS +=

else # KERNELRELEASE

CROSS_PROGS :=
HOST_PROGS :=
SCRIPT_FILES :=
CFLAGS +=
LDFLAGS +=

include ../kernel_env.mk

endif # KERNELRELEASE

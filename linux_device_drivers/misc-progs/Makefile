ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m	:=
scull-objs	:=

# Specify flags for the module compilation.
EXTRA_CFLAGS +=

else # KERNELRELEASE

CROSS_PROGS := nbtest load50 mapcmp polltest mapper setlevel setconsole inp outp datasize dataalign netifdebug
HOST_PROGS :=
SCRIPT_FILES :=
CFLAGS += -O2 -fomit-frame-pointer -Wall -I$(KERNELDIR)/include
LDFLAGS +=

include ../kernel_env.mk

endif # KERNELRELEASE

# Comment/uncomment the following line to disable/enable debugging
#DEBUG = y

# Add your debugging flag (or not) to CFLAGS
ifeq ($(DEBUG),y)
    DEBFLAGS = -O -g -DSCULL_DEBUG # "-O" is needed to expand inlines
else
    DEBFLAGS = -O2
endif

ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m	:= scull.o
scull-objs	:= main.o pipe.o access.o

# Specify flags for the module compilation.
EXTRA_CFLAGS += $(DEBFLAGS) -I$$PWD/../include

else # KERNELRELEASE

CROSS_PROGS :=
HOST_PROGS :=
SCRIPT_FILES := scull.init scull_load scull_unload
CFLAGS +=
LDFLAGS +=

include ../kernel_env.mk

endif # KERNELRELEASE

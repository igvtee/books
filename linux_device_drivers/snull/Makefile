# Comment/uncomment the following line to disable/enable debugging
DEBUG = y


# Add your debugging flag (or not) to CFLAGS
ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSNULL_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

ifneq ($(KERNELRELEASE),)
# call from kernel build system
obj-m	:= snull.o

# Specify flags for the module compilation.
EXTRA_CFLAGS += -Wall -Werror $(DEBFLAGS) -I$$PWD/../include

else # KERNELRELEASE

CROSS_PROGS :=
HOST_PROGS :=
SCRIPT_FILES := snull_load snull_unload
CFLAGS +=
LDFLAGS +=

include ../kernel_env.mk

endif # KERNELRELEASE

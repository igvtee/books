
# Comment/uncomment the following line to enable/disable debugging
DEBUG = y


ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSCULLV_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

ifneq ($(KERNELRELEASE),)

scullv-objs := main.o mmap.o
obj-m	:= scullv.o
EXTRA_CFLAGS += -Wall -Werror $(DEBFLAGS) -I$$PWD/../include

else

CROSS_PROGS :=
HOST_PROGS :=
SCRIPT_FILES := scullv_load scullv_unload
CFLAGS +=
LDFLAGS +=

include ../kernel_env.mk

endif

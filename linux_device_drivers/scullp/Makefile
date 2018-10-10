
# Comment/uncomment the following line to enable/disable debugging
DEBUG = y


ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSCULLP_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

ifneq ($(KERNELRELEASE),)

scullp-objs := main.o mmap.o
obj-m	:= scullp.o
EXTRA_CFLAGS += -Wall -Werror $(DEBFLAGS) -I$$PWD/../include

else

CROSS_PROGS :=
HOST_PROGS :=
SCRIPT_FILES := scullp_load scullp_unload
CFLAGS +=
LDFLAGS +=

include ../kernel_env.mk

endif

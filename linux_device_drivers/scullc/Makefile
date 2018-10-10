
# Comment/uncomment the following line to enable/disable debugging
DEBUG = y


ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSCULLC_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

ifneq ($(KERNELRELEASE),)

scullc-objs := main.o
obj-m	:= scullc.o
EXTRA_CFLAGS += -Wall -Werror $(DEBFLAGS) -I$$PWD/../include

else

CROSS_PROGS :=
HOST_PROGS :=
SCRIPT_FILES := scullc_load scullc_unload
CFLAGS +=
LDFLAGS +=

include ../kernel_env.mk

endif

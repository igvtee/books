
# Comment/uncomment the following line to enable/disable debugging
DEBUG = y


ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSCULLD_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

ifneq ($(KERNELRELEASE),)

sculld-objs := main.o mmap.o
obj-m	:= sculld.o
EXTRA_CFLAGS += -Wall -Werror $(DEBFLAGS) -I${PWD}/../include

else

CROSS_PROGS :=
HOST_PROGS :=
SCRIPT_FILES := sculld_load sculld_unload
CFLAGS +=
LDFLAGS +=

include ../kernel_env.mk

endif

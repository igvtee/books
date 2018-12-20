# Comment/uncomment the following line to disable/enable debugging
#DEBUG = y


# Add your debugging flag (or not) to CFLAGS
ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSBULL_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

ifneq ($(KERNELRELEASE),)
# call from kernel build system

obj-m	:= sbull.o
EXTRA_CFLAGS += -Wall -Werror $(DEBFLAGS) -I$$PWD/../include

else

CROSS_PROGS :=
HOST_PROGS :=
SCRIPT_FILES := sbull_load sbull_unload
CFLAGS +=
LDFLAGS +=

include ../kernel_env.mk

endif

# Comment/uncomment the following line to disable/enable debugging
DEBUG = y

# Add your debugging flag (or not) to CFLAGS
ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

ifneq ($(KERNELRELEASE),)
# Kernel modules
obj-m	:= lddbus.o

# Specify flags for the module compilation.
EXTRA_CFLAGS += -Wall -Werror $(DEBFLAGS) -I${PWD}/../include

else

CROSS_PROGS :=
HOST_PROGS :=
SCRIPT_FILES :=
CFLAGS +=
LDFLAGS +=

include ../kernel_env.mk

endif

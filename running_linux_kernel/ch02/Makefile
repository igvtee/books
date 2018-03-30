ifneq ($(KERNELRELEASE),)
	obj-m := fcache.o
else
include ../kernel_env.mk

all:
	$(MAKE) -C $(KDIR) M=$$PWD modules

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif

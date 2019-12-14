ifneq ($(KERNELRELEASE),)
	obj-m := fcache.o
else
include ../kernel_env.mk

all:
	echo $(PATH)
	$(MAKE) -C $(KDIR) M=$$PWD O=$(BUILD_DIR) modules

clean:
	$(MAKE) -C $(KDIR) M=$$PWD O=$(BUILD_DIR) clean
endif

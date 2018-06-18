ARCH ?= arm
CROSS_COMPILE ?= arm-linux-gnueabi-
KDIR ?= ../../qemu_linux/linux-4.0
MOD_DIR ?= ../../qemu_linux/rootfs

export ARCH CROSS_COMPILE

.PHONY: all clean install
all: $(CROSS_PROGS) $(HOST_PROGS) $(ASSEMBLE)
	$(MAKE) -C $(KDIR) M=$(CURDIR) modules

$(CROSS_PROGS): CC=$(CROSS_COMPILE)gcc

clean:
	@rm -f $(CROSS_PROGS) $(HOST_PROGS) $(ASSEMBLE) *.o
	$(MAKE) -C $(KDIR) M=$$PWD clean

install:
	INSTALL_MOD_PATH=$(MOD_DIR) $(MAKE) -C $(KDIR) M=$(CURDIR) modules_install
	@[ -z "$(CROSS_PROGS)" ] || cp $(CROSS_PROGS) -f $(MOD_DIR)/usr/bin/

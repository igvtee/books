ARCH ?= arm
CROSS_COMPILE ?= arm-linux-gnueabi-
ROOT_DIR:=${shell pwd}/../..
KDIR ?= ${ROOT_DIR}/qemu_linux/linux-4.0
TC_PATH=${ROOT_DIR}/qemu_linux/toolchain/gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabi
PATH:=${PATH}:${TC_PATH}/bin
BUILD_DIR:=${ROOT_DIR}/qemu_linux/build/${ARCH}/linux
MOD_DIR:=${ROOT_DIR}/qemu_linux/rootfs

export ARCH CROSS_COMPILE PATH

.PHONY: all clean install
all: $(CROSS_PROGS) $(HOST_PROGS) $(ASSEMBLE)
	$(MAKE) -C $(KDIR) M=$(CURDIR) O=$(BUILD_DIR) modules

$(CROSS_PROGS): CC=$(CROSS_COMPILE)gcc

clean:
	@rm -f $(CROSS_PROGS) $(HOST_PROGS) $(ASSEMBLE) *.o
	$(MAKE) -C $(KDIR) M=$$PWD O=$(BUILD_DIR) clean

install:
	INSTALL_MOD_PATH=$(MOD_DIR) $(MAKE) -C $(KDIR) O=$(BUILD_DIR) M=$(CURDIR) modules_install
	@[ -z "$(CROSS_PROGS)" ] || cp $(CROSS_PROGS) -f $(MOD_DIR)/usr/bin/

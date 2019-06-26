LINUX_DIR=linux-4.0
LINUX_PACKAGE=${LINUX_DIR}.tar.gz
BUSYBOX_DIR=busybox-1.24.0
BUSYBOX_PACKAGE=${BUSYBOX_DIR}.tar.bz2

ARCH=i386
# environment
ifeq (${ARCH},arm)
  CROSS_NAME=arm-linux-gnueabi
  LIBC_PATH=lib
endif
ifeq (${ARCH},arm64)
  CROSS_NAME=aarch64-linux-gnu
  LIBC_PATH=lib64
endif
ifeq (${ARCH},i386)
  CROSS_NAME=i686-pc-linux-gnu
  LIBC_PATH=lib
endif
CROSS_COMPILE=${CROSS_NAME}-
export ARCH CROSS_COMPILE

all: initramfs.cpio.gz linux

${LINUX_PACKAGE}:
	wget https://www.kernel.org/pub/linux/kernel/v4.x/${LINUX_PACKAGE}

${LINUX_DIR}: ${LINUX_PACKAGE}
	tar zxf ${LINUX_PACKAGE}
	touch ${LINUX_DIR}

${BUSYBOX_PACKAGE}:
	wget https://busybox.net/downloads/${BUSYBOX_PACKAGE}

${BUSYBOX_DIR}: ${BUSYBOX_PACKAGE}
	tar jvxf ${BUSYBOX_PACKAGE}
	touch ${BUSYBOX_DIR}

build/${ARCH}/busybox/_install/bin/busybox: ${BUSYBOX_DIR} build/${ARCH}/busybox/.config
	cd build/${ARCH}/busybox && make install

build/${ARCH}/busybox/.config:
	mkdir -p build/${ARCH}/busybox
	cd ${BUSYBOX_DIR} && make O=${shell pwd}/build/${ARCH}/busybox defconfig
	sed -i -e 's/.*\(CONFIG_STATIC\).*/\1=y/' build/${ARCH}/busybox/.config
	cd ${BUSYBOX_DIR} && make O=${shell pwd}/build/${ARCH}/busybox oldconfig

busybox: build/${ARCH}/busybox/_install/bin/busybox

rootfs_libs:
	mkdir -p rootfs/lib
	cp -af /usr/${CROSS_NAME}/${LIBC_PATH}/ld-* rootfs/lib
	cp -af /usr/${CROSS_NAME}/${LIBC_PATH}/libc-* rootfs/lib
	cp -af /usr/${CROSS_NAME}/${LIBC_PATH}/libc.* rootfs/lib
	cp -af /usr/${CROSS_NAME}/${LIBC_PATH}/libm-* rootfs/lib
	cp -af /usr/${CROSS_NAME}/${LIBC_PATH}/libm.* rootfs/lib

rootfs: busybox rootfs_libs
	mkdir -p rootfs
	cp -a build/${ARCH}/busybox/_install/* rootfs
	mkdir -p rootfs/usr/share/udhcpc/
	cp ${BUSYBOX_DIR}/examples/udhcp/simple.script rootfs/usr/share/udhcpc/default.script
	cd rootfs; mkdir -p etc/init.d dev mnt proc sys tmp lib/modules
	echo -e "/bin/mount -a\necho /sbin/mdev > /proc/sys/kernel/hotplug\nmdev -s" > rootfs/etc/init.d/rcS
	chmod +x rootfs/etc/init.d/rcS
	echo -e "proc /proc proc defaults 0 0\ntmpfs /tmp tmpfs defaults 0 0\nsysfs /sys sysfs default 0 0\ntmpfs /dev tmpfs default 0 0\ndebugfs /sys/kernel/debug debugfs default 0 0" > rootfs/etc/fstab
	echo -e "::sysinit:/etc/init.d/rcS\n::respawn:-/bin/sh\n::askfirst:-/bin/sh\n::ctrlaltdel:/bin/umount -a -r" > rootfs/etc/inittab
	[ -e rootfs/dev/console ] || sudo mknod rootfs/dev/console c 5 1

initramfs.cpio.gz: rootfs
	cd rootfs; find . -print0 | cpio --null -ov --format=newc | gzip -9 > ../initramfs.cpio.gz

zImage.arm: ${LINUX_DIR}
	mkdir -p build/${ARCH}/linux
	cd ${LINUX_DIR}; make mrproper
	$(if $(wildcard build/${ARCH}/linux/.config), \
	  cd ${LINUX_DIR}; make O=${shell pwd}/build/${ARCH}/linux/ oldconfig , \
	  cd ${LINUX_DIR}; make O=${shell pwd}/build/${ARCH}/linux/ vexpress_defconfig)
	cd build/${ARCH}/linux/; make all
	cd build/${ARCH}/linux/; INSTALL_MOD_PATH="../../../../rootfs" make modules_install
	cp build/${ARCH}/linux/arch/${ARCH}/boot/zImage $@

zImage.arm64: ${LINUX_DIR}
	mkdir -p build/${ARCH}/linux
	cd ${LINUX_DIR}; make mrproper
	$(if $(wildcard build/${ARCH}/linux/.config), \
	  cd ${LINUX_DIR}; make O=${shell pwd}/build/${ARCH}/linux/ oldconfig , \
	  cd ${LINUX_DIR}; make O=${shell pwd}/build/${ARCH}/linux/ defconfig)
	cd build/${ARCH}/linux/; make all
	cd build/${ARCH}/linux/; INSTALL_MOD_PATH="../../../../rootfs" make modules_install
	cp build/${ARCH}/linux/arch/${ARCH}/boot/Image.gz $@

zImage.i386: ${LINUX_DIR}
	mkdir -p build/${ARCH}/linux
	cd ${LINUX_DIR}; make mrproper
	$(if $(wildcard build/${ARCH}/linux/.config), \
	  cd ${LINUX_DIR}; make O=${shell pwd}/build/${ARCH}/linux/ oldconfig , \
	  cd ${LINUX_DIR}; make O=${shell pwd}/build/${ARCH}/linux/ defconfig)
	cd build/${ARCH}/linux/; make CONFIG_DEBUG_INFO=y all
	cd build/${ARCH}/linux/; INSTALL_MOD_PATH="../../../../rootfs" make modules_install
	cp build/${ARCH}/linux/arch/${ARCH}/boot/bzImage $@

linux: zImage.${ARCH}

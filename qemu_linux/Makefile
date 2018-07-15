LINUX_DIR=linux-4.0
LINUX_PACKAGE=${LINUX_DIR}.tar.gz
BUSYBOX_DIR=busybox-1.24.0
BUSYBOX_PACKAGE=${BUSYBOX_DIR}.tar.bz2

# environment
ARCH=arm
CROSS_NAME=arm-linux-gnueabi
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

${BUSYBOX_DIR}/_install/bin/busybox: ${BUSYBOX_DIR} ${BUSYBOX_DIR}/.config
	make -C ${BUSYBOX_DIR} install

${BUSYBOX_DIR}/.config:
	cd ${BUSYBOX_DIR}; make defconfig
	sed -i -e 's/.*\(CONFIG_STATIC\).*/\1=y/' ${BUSYBOX_DIR}/.config
	cd ${BUSYBOX_DIR}; make oldconfig 

busybox: ${BUSYBOX_DIR}/_install/bin/busybox

rootfs_libs:
	mkdir -p rootfs/lib
	cp -af /usr/${CROSS_NAME}/lib/ld-* rootfs/lib
	cp -af /usr/${CROSS_NAME}/lib/libc-* rootfs/lib
	cp -af /usr/${CROSS_NAME}/lib/libc.* rootfs/lib
	cp -af /usr/${CROSS_NAME}/lib/libm-* rootfs/lib
	cp -af /usr/${CROSS_NAME}/lib/libm.* rootfs/lib

rootfs: busybox rootfs_libs
	mkdir -p rootfs
	cp -a ${BUSYBOX_DIR}/_install/* rootfs
	cd rootfs; mkdir -p etc/init.d dev mnt proc sys tmp lib/modules
	echo -e "/bin/mount -a\necho /sbin/mdev > /proc/sys/kernel/hotplug\nmdev -s" > rootfs/etc/init.d/rcS
	chmod +x rootfs/etc/init.d/rcS
	echo -e "proc /proc proc defaults 0 0\ntmpfs /tmp tmpfs defaults 0 0\nsysfs /sys sysfs default 0 0\ntmpfs /dev tmpfs default 0 0\ndebugfs /sys/kernel/debug debugfs default 0 0" > rootfs/etc/fstab
	echo -e "::sysinit:/etc/init.d/rcS\n::respawn:-/bin/sh\n::askfirst:-/bin/sh\n::ctrlaltdel:/bin/umount -a -r" > rootfs/etc/inittab
	[ -e rootfs/dev/console ] || sudo mknod rootfs/dev/console c 5 1

initramfs.cpio.gz: rootfs
	cd rootfs; find . -print0 | cpio --null -ov --format=newc | gzip -9 > ../initramfs.cpio.gz

zImage.arm32: ${LINUX_DIR}
	cd ${LINUX_DIR}; make vexpress_defconfig
	cd ${LINUX_DIR}; make bzImage dtbs
	cd ${LINUX_DIR}; make modules
	cd ${LINUX_DIR}; INSTALL_MOD_PATH="../rootfs" make modules_install
	cp linux-4.0/arch/arm/boot/zImage $@

linux: zImage.arm32

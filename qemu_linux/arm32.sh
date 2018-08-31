#!/bin/sh
qemu-system-arm -M vexpress-a9 -smp 4 -m 512M -kernel zImage.arm -initrd initramfs.cpio.gz -append "rdinit=/linuxrc console=ttyAMA0 loglevel=8 earlyprintk" -dtb build/arm/linux/arch/arm/boot/dts/vexpress-v2p-ca9.dtb -nographic

# kernel gdb
# arm-linux-gnueabi-gdb ./vmlinux
# target remote 127.0.0.1:1234
# b start_kernel
#
# kernel module gdb
# b sys_init_module
# modprobe sequence
# cat /sys/module/sequence/sections/.text (0x7f000000)
# cat /sys/module/sequence/sections/.bss (0x7f0023dc)
# cat /sys/module/sequence/sections/.data (0x7f001f58)
# add-symbol-file ../../linux_device_drivers/misc-modules/sequence.ko 0x7f000000 -s .bss 0x7f0023dc -s .data 0x7f001f58
#qemu-system-arm -S -s -M vexpress-a9 -smp 4 -m 512M -kernel zImage.arm -initrd initramfs.cpio.gz -append "rdinit=/linuxrc console=ttyAMA0 loglevel=8 earlyprintk" -dtb build/arm/linux/arch/arm/boot/dts/vexpress-v2p-ca9.dtb -nographic

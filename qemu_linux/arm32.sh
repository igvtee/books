#!/bin/sh
qemu-system-arm -M vexpress-a9 -smp 4 -m 512M -kernel zImage.arm32 -initrd initramfs.cpio.gz -append "rdinit=/linuxrc console=ttyAMA0 loglevel=8 earlyprintk" -dtb linux-4.0/arch/arm/boot/dts/vexpress-v2p-ca9.dtb -nographic

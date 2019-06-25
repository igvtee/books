#!/bin/sh
qemu-system-x86_64 -smp 4 -m 512 -kernel zImage.i386 -initrd initramfs.cpio.gz -append "rdinit=/linuxrc console=ttyS0" -nographic

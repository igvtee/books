#!/bin/sh
qemu-system-i386 -S -s -smp 4 -m 512 -kernel zImage.i386 -initrd initramfs.cpio.gz -append "rdinit=/linuxrc console=ttyS0" -nographic

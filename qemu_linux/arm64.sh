#!/bin/sh
qemu-system-aarch64 -M virt -smp 4 -m 512 -cpu cortex-a57 -kernel zImage.arm64 -initrd initramfs.cpio.gz -append "rdinit=/linuxrc console=ttyAMA0 loglevel=8 earlyprintk" -nographic

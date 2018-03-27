#!/bin/sh
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabi-
KERNEL_PATH=~/programs/running_linux_kernel/runninglinuxkernel_4.0/
echo ${KERNEL_PATH}
make -C ${KERNEL_PATH} M=`pwd` clean
make -C ${KERNEL_PATH} M=`pwd` modules

ARCH ?= arm
CROSS_COMPILE ?= arm-linux-gnueabi-
ROOT_DIR:=${shell pwd}/../..
KDIR ?= ${ROOT_DIR}/qemu_linux/linux-4.0
TC_PATH=${ROOT_DIR}/qemu_linux/toolchain/gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabi
PATH:=${PATH}:${TC_PATH}/bin
BUILD_DIR:=${ROOT_DIR}/qemu_linux/build/${ARCH}/linux

export ARCH CROSS_COMPILE PATH

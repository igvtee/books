#!/bin/sh
set -e 

modprobe vfio-pci
./dpdk_nic_bind.py --bind=vfio-pci 04:00.0 05:00.0
./dpdk_setup_ports.py
#./t-rex-64 -i
#./t-rex-64 -i --astf

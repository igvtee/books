#!/bin/sh

ip link add name br0 type bridge
ip link set dev br0 up
ip link set dev enp5s0 up
ip link set dev enp6s0 up
ip link set dev enp5s0 master br0
ip link set dev enp6s0 master br0

#ip link set enp5s0 nomaster
#ip link set enp6s0 nomaster
#ip link delete br0

#!/bin/sh

echo 1 > /proc/sys/net/ipv4/ip_forward
echo 1 > /proc/sys/net/ipv6/conf/enp5s0/disable_ipv6
echo 1 > /proc/sys/net/ipv6/conf/enp6s0/disable_ipv6
ip link set dev enp5s0 up
ip link set dev enp6s0 up
ip a a 11.11.11.1/24 brd + dev enp5s0
ip a a 12.12.12.1/24 brd + dev enp6s0
ip r a 16.0.0.0/8 via 11.11.11.2
ip r a 48.0.0.0/8 via 12.12.12.2
ip neigh add 11.11.11.2 lladdr 7c:2b:e1:12:ce:b5 dev enp5s0
ip neigh add 12.12.12.2 lladdr 7c:2b:e1:12:ce:b3 dev enp6s0

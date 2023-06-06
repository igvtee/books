
all: xdp-example.o tc-example.o

# ip link set dev enp4s0 xdp obj xdp-example.o
# ip link set dev enp4s0 xdp off
xdp-example.o: xdp-example.c
	clang -O2 -g -Wall -target bpf -c xdp-example.c -o $@

# tc qdisc add dev enp4s0 clsact
# tc filter add dev enp4s0 ingress bpf da obj tc-example.o sec ingress
# tc filter add dev enp4s0 egress bpf da obj tc-example.o sec egress
# tc filter show dev enp4s0 ingress
# tc filter show dev enp4s0 egress
# tc filter del dev enp4s0 ingress
# tc filter del dev enp4s0 egress
# tc qdisc del dev enp4s0 clsact
tc-example.o: tc-example.c
	clang -O2 -Wall -target bpf -c tc-example.c -o $@

# llvm-mc -triple bpf -filetype=obj -o xdp-example.o xdp-example.S
# llvm-objdump -S --no-show-raw-insn xdp-example.o 
xdp-example.S: xdp-example.c vmlinux.h
	clang -O2 -S -Wall -target bpf -c xdp-example.c -o $@

vmlinux.h:
	cp /usr/src/linux/samples/bpf/vmlinux.h .

# pahole xdp-example.o
xdp-example.bc: xdp-example.c vmlinux.h  
	clang -O2 -g -Wall -target bpf -emit-llvm -c xdp-example.c -o $@
	llc $@ -march=bpf -mcpu=probe -mattr=dwarfris -filetype=obj -o xdp-example.o

32-bit-example.S: 32-bit-example.c
	clang -target bpf -emit-llvm -S 32-bit-example.c
	llc -march=bpf 32-bit-example.ll -o 32-bit-example.S
	llc -march=bpf -mattr=+alu32 32-bit-example.ll -o 32-bit-example-alu32.S

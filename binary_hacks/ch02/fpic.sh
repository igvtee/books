#!/bin/sh
rm -f *.o *.so
num=1000
for i in `seq $num`; do
	echo "void func$i() {" > fpic$i.c
	ruby -e "10000.times { puts 'printf(\"\");' }" >> fpic$i.c
	echo "}" >> fpic$i.c
	gcc -m32 -fno-builtin -o fpic-no-pic$i.o -c fpic$i.c
	gcc -m32 -fno-builtin -fPIC -o fpic-pic$i.o -c fpic$i.c
done

gcc -m32 -shared -o fpic-no-pic.so fpic-no-pic*.o
gcc -m32 -shared -o fpic-pic.so fpic-pic*.o

echo "int main() { return 0; }" > fpic-main.c
gcc -m32 -o fpic-no-pic fpic-main.c ./fpic-no-pic.so
gcc -m32 -o fpic-pic fpic-main.c ./fpic-pic.so

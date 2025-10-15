all: hello bubble_sort bubble

hello: hello.c
	gcc -g -o $@ $<

bubble_sort: bubble_sort.c
	gcc -g -fno-stack-protector -O2 -o $@ $<

bubble: bubble.c
	gcc -g -o $@ $<
# gdb bubble -x bubble.fix

clean:
	rm -f hello bubble_sort bubble

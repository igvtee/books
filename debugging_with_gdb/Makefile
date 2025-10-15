all: hello bubble_sort

hello: hello.c
	gcc -g -o $@ $<

bubble_sort: bubble_sort.c
	gcc -g -fno-stack-protector -O2 -o $@ $<

clean:
	rm -f hello bubble_sort

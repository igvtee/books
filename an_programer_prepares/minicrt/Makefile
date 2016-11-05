CC=gcc
CFLAGS=-m32 -fno-builtin -nostdlib -fno-stack-protector -g
#LDFLAGS=-Wl,--start-group minicrt.a -Wl,--end-group \
	-Wl,-e,mini_crt_entry entry.o
DEPS=mimicrt.h
LIB_OBJS=malloc.o stdio.o string.o printf.o
MINICRT_LIB=minicrt.a
TARGETS=test

all: $(MINICRT_LIB) entry.o $(TARGETS)

test: test.o $(MINICRT_LIB)
	$(LD) -m elf_i386 -static -e mini_crt_entry entry.o $< $(MINICRT_LIB) -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(MINICRT_LIB): $(LIB_OBJS)
	$(AR) -rs $@ $^

.PHONY: clean
clean:
	rm -f *.o $(MINICRT_LIB) $(TARGETS) test.txt

VPATH = ../ch5
program := value lrvalue find_char del_substr reverse_string eratosthenes \
	eratosthenes_bit eratosthenes_num

.PHONY: all clean
all: $(program)

clean:
	@rm -f $(program) *.o

eratosthenes_bit eratosthenes_num: CFLAGS += -D__BITS_LIB__ -I../ch5
eratosthenes_bit eratosthenes_num: bit.c

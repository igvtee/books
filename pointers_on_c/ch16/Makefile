program := div rand strtol float_error clock vprintf atexit \
	assert env system qsort bsearch locale localeconv \
	strtol1 rand1 clock1 military_time set_buffer sigfpe1 \
	sigfpe2 age_radix rand2 child_time day_of_week rand3 \
	ages birthday

.PHONY: all clean
all: $(program)

float_error: CFLAGS+=-lm

clean:
	@rm -f $(program) *.o *.s

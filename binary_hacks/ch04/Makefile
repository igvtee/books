#CFLAGS=-Wall -Wextra -Wformat=2 -Wstrict-aliasing=2 -Wcast-qual -Wcast-align \
	-Wwrite-strings -Wconversion -Wfloat-equal -Wpointer-arith -Wswitch-enum
CFLAGS=-g

export LC_MESSAGES=C
EXECS = alias my_printf double_free my_atoi int_min testflap fortify_foo \
	fortify_bar fortify_baz overf bitmask bitmask_m32 tst null \
	async_signal_unsafe non_volatile sigwait sigsafe01 sigsafe02 sigsafe03 \
	sigsafe04 sigsafe05 sigsafe06 valgrind_test1 horrible data_race

all: $(EXECS)

alias: alias.c
	$(CC) $(CFLAGS) -O2 -Wstrict-aliasing=2 -o $@ $<

my_printf: my_printf.c
	$(CC) $(CFLAGS) -Wformat=2 -o $@ $<

double_free: double_free.c
	$(CC) $(CFLAGS) -o $@ $<

my_atoi: my_atoi.c
	$(CC) $(CFLAGS) -m32 -ftrapv -o $@ $<

testflap: testflap.c
	$(CC) $(CFLAGS) -fsanitize=address -o $@ $<

fortify_foo: fortify_foo.c # -D_FORTIFY_SOURCE=1
	$(CC) $(CFLAGS) -O1 -o $@ $<

fortify_bar: fortify_bar.c # -D_FORTIFY_SOURCE=1
	$(CC) $(CFLAGS) -O1 -o $@ $<

fortify_baz: fortify_baz.c
	$(CC) $(CFLAGS) -O1 -o $@ $<

overf: overf.c
	$(CC) $(CFLAGS) -fstack-protector -o $@ $<

bitmask_m32: bitmask.c
	$(CC) $(CFLAGS) -m32 -o $@ $<

async_signal_unsafe: async_signal_unsafe.c
	$(CC) $(CFLAGS) -lpthread -o $@ $<

non_volatile: non_volatile.c
	$(CC) $(CFLAGS) -O2 -o $@ $<

sigwait: sigwait.c
	$(CC) $(CFLAGS) -O2 -lpthread -o $@ $<

sigsafe06: sigsafe06.c
	$(CC) $(CFLAGS) -I./sigsafe-0.1.3/src -L./sigsafe-0.1.3/build-x86_64-linux-st/ \
	-o $@ $< -lsigsafe

valgrind_test1: valgrind_test1.cpp
	$(CXX) $(CXXFLAGS) -g -O0 -o $@ $<

data_race: data_race.c
	$(CC) $(CFLAGS) -g -O0 -o $@ $< -lpthread

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY:clean usage
clean:
	rm -f $(EXECS)

usage:
	@echo "   === example usage ==="
	@echo "MALLOC_CHECK_=1 ./double_free"
	@echo "./my_atoi 4294967297"
	@echo "./fortify_bar 123456"
	@echo "./fortify_baz %n"
	@echo "./overf 012345678"
	@echo "valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./valgrind_test1"
	@echo "valgrind --tool=helgrind ./data_race"

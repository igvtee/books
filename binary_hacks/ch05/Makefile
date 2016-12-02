CFLAGS=-g

export LC_MESSAGES=C
EXECS = syscall-func01 syscall-func02 syscall-func03 dlsay divbyzero backtrace01 \
		backtrace02 readlink showsolibs01 malloc dumpsymbols01 dumpsymbols02 ffcall01 \
		ffcall02 ffcall03 dump_sample load_hello unwind01 unwind02 unwind03 stackbase \
		stackthread sigaltstack01 sigaltstack02 sigaltstack03 signaleip
LIBS = gethostname.so bindwrap.so hello.so stack_usage.so audit.so

all: $(EXECS) $(LIBS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.so: %.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $<

bindwrap.so: bindwrap.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $< -ldl

dlsay: dlsay.c
	$(CC) $(CFLAGS) -o $@ $< -ldl

backtrace01: backtrace01.c
	$(CC) $(CFLAGS) -rdynamic -o $@ $<

dumpsymbols01: dumpsymbols01.c
	$(CC) $(CFLAGS) -DPACKAGE -DPACKAGE_VERSION -o $@ $< -lbfd

dumpsymbols02: dumpsymbols02.c
	$(CC) $(CFLAGS) -DPACKAGE -DPACKAGE_VERSION -o $@ $< -lbfd

ffcall01: ffcall01.c
	$(CC) $(CFLAGS) -o $@ $< -lavcall

ffcall02: ffcall02.c
	$(CC) $(CFLAGS) -o $@ $< -lavcall -ldl

ffcall03: ffcall03.c
	$(CC) $(CFLAGS) -I/usr/lib64/libffi-3.0.13/include/ -o $@ $< -lffi

dwarf: dwarf.c
	$(CC) $(CFLAGS) -o $@ $< -lelf -ldw

hello01.o: hello01.c
	$(CC) $(CFLAGS) -c $<

load_hello: load_hello.c hello01.o
	$(CC) $(CFLAGS) -DPACKAGE -DPACKAGE_VERSION -o $@ $< -lbfd -ldl

unwind01: unwind01.c
	$(CC) $(CFLAGS) -o $@ $< -lunwind

unwind02: unwind02.c
	$(CC) $(CFLAGS) -o $@ $< -lunwind

stackthread: stackthread.c
	$(CC) $(CFLAGS) -o $@ $< -lpthread -ldl

sigaltstack01: sigaltstack01.c
	$(CC) $(CFLAGS) -o $@ $< -finstrument-functions

sigaltstack02: sigaltstack02.c
	$(CC) $(CFLAGS) -o $@ $< -lpthread

signaleip: signaleip.c
	$(CC) $(CFLAGS) -m32 -o $@ $<

.PHONY:clean usage
clean:
	rm -f $(EXECS) $(LIBS)

usage:
	@echo "   === example usage ==="
	@echo "FAKE_HOSTNAME=sai.fsij.org LD_PRELOAD=./gethostname.so hostname"
	@echo "LD_PRELOAD=./bindwrap.so BIND_ADDR=127.0.0.1 nc -4 -l -p 4545"
	@echo "./dlsay ./hello.so hello world"
	@echo "./backtrace01 | egrep -o '0x[0-9a-f]{6,13}' | addr2line -f -e backtrace01"
	@echo "LD_PRELOAD=/lib/libSegFault.so SEGFAULT_SIGNALS=all ./divbyzero"
	@echo "./ffcall02 puts s \"hello world\""
	@echo "LD_PRELOAD=./stack_usage.so ./sigaltstack01"
	@echo "LD_AUDIT=./audit.so ./readlink"

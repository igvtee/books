CFLAGS=-fno-builtin -g
CXXFLAGS=
MYLDFLAGS=-Wl,-rpath,'$$ORIGIN' -Wl,-rpath-link,'./'
ASSM=user_agent.s
OBJS=
LIBS=libfoo.so test.so
EXECS=inline hello threadlocal weak-main vertest1 vertest2 main maincxx trampoline trampoline-mod heap foo call-foo factorial
OBJCOPY=objcopy

all: $(OBJS) $(LIBS) $(EXECS) $(ASSM)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%: %.o
	$(CC) $< -o $@

%.so: %.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

%.s: %.c
	$(CC) -fverbose-asm -S $<

hello: hello.c
	$(CC) -Os -fno-builtin -fomit-frame-pointer -fno-ident -c $<
	$(LD) --entry=hello -o $@ $@.o

threadlocal: threadlocal.c
	$(CC) $(CFLAGS) -lpthread -o $@ $<

weak-main: weak-main.c weak.so
	$(CC) $(CFLAGS) $(MYLDFLAGS) -o $@ $^

libfoo.so:
	$(CC) $(CFLAGS) -fPIC -c a.c
	$(CC) $(CFLAGS) -fPIC -c b.c
	$(CC) $(CFLAGS) -shared -o $@ a.o b.o -Wl,--version-script,libfoo.map
	
test.so: test.cc
	$(CXX) -shared -fvisibility=hidden -o $@ $<

vertest1: libmax1.c vertest1.c
	$(CC) $(CFLAGS) -Wl,-soname,libmax.so.1 -fPIC -shared -o libmax.so.1.0 libmax1.c
	ln -sf libmax.so.1.0 libmax.so.1
	$(CC) $(CFLAGS) $(MYLDFLAGS) -o $@ vertest1.c libmax.so.1

vertest2: libmax2.c vertest2.c
	$(CC) $(CFLAGS) -Wl,-soname,libmax.so.1 -Wl,--version-script,libmax2.def -fPIC -shared -o libmax.so.2.0 libmax2.c
	ln -sf libmax.so.2.0 libmax.so.1
	$(CC) $(CFLAGS) $(MYLDFLAGS) -o $@ vertest2.c libmax.so.1
	$(CC) $(CFLAGS) -Wl,-soname,libmax.so.1 -Wl,--version-script,libmax3.def -fPIC -shared -o libmax.so.2.1 libmax3.c

maincxx: maincxx.cpp
	$(CXX) -o $@ $<

trampoline-mod: trampoline.o
	$(OBJCOPY) --set-section-flags .note.GNU-stack= trampoline.o trampoline-mod.o
	$(CC) $(CFLAGS) -o $@ trampoline-mod.o

foo: foo.c
	$(CC) $(CFLAGS) -fPIE -pie -o $@ $<

call-foo: call-foo.c foo.c
	$(CC) $(CFLAGS) -fPIE -c foo.c
	$(CC) $(CFLAGS) -rdynamic -o foo1 -pie foo.o
	$(CC) $(CFLAGS) $(MYLDFLAGS) -o $@ call-foo.c foo1
	
factorial: factorial.c
	$(CC) $(CFLAGS) -ldl -fPIE -rdynamic -pie -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS) $(LIBS) $(EXECS) $(ASSM) *.o *.a *.so *.s *.so.*

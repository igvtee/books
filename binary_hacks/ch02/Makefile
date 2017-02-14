CFLAGS=-fno-builtin
CXXFLAGS=
MYLDFLAGS=-Wl,-rpath,'$$ORIGIN' -Wl,-rpath-link,'./'
OBJS=dbg.o dbg_cxx.o
LIBS=libfoo.a libfoo.so fpic-no-pic.so fpic-pic.so
EXECS=baz hello supfoo utf8 test sample
OBJCOPY=objcopy

all: $(OBJS) $(LIBS) $(EXECS)

%.so: %.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

libfoo.a: foo.o bar.o
	$(AR) ruv $@ $^

libfoo.so: foo.c bar.c
	$(CC) $(CFLAGS) -fPIC -c foo.c
	$(CC) $(CFLAGS) -fPIC -c bar.c
	$(CC) -shared -Wl,-soname,libfoo.so.0 -o libfoo.so foo.o bar.o

baz: baz.o
	$(CC) $(CFLAGS) -o $@ $< -L. -lfoo

hello.o: hello.c
	$(CC) $(CFLAGS) -g -c hello.c

supfoojpg.o: supfoo.jpg
	$(OBJCOPY) -I binary -O elf64-x86-64 -B i386 $< $@

supfoo: supfoo.c supfoojpg.o
	$(CC) $(CFLAGS) -o $@ $^

test: test.c
	$(CC) $(CFLAGS) -g -o $@ $<

dbg_cxx.o: dbg.c
	$(CXX) -c -o $@ $<

sample: sample.cpp dbg.o
	$(CXX) -c $<
	$(CXX) -o $@ $@.o dbg.o

fpic-no-pic.so: fpic.c
	$(CC) $(CFLAGS) -m32 -shared -o $@ $<

fpic-pic.so: fpic.c
	$(CC) $(CFLAGS) -m32 -shared -fPIC -o $@ $<

main: a.o b.o main.o
	$(CC) -o main a.o b.o main.o

libsym.so: a.c b.c
	$(CC) -fPIC -c a.c
	$(CC) -fPIC -c b.c
	$(CC) -shared -o $@ a.o b.o

libsym.a: a.o b.o
	$(AR) cr $@ $^

main-static: main.o libsym.a
	$(CC) -o $@ $^

main-dynamic: a.so b.so main.so
	$(CC) $(MYLDFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS) $(LIBS) $(EXECS) *.o *.a *.so

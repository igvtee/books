CFLAGS=-m32 -fno-stack-protector
CXXFLAGS=-m32
MYLDFLAGS=-Wl,-rpath,'$$ORIGIN' -Wl,-rpath-link,'./'
OBJS=SimpleSection.o CustonSection.o WeakSymbol.o
LIBS=Lib.so pic.so lib.so
EXECS=ImageSection SpecialSymbol ManualNameMangling WeakReference pthread \
      pthread_mul ab HelloWorld TinyHelloWorld target SectionMapping \
      HeapSize Program1 Program2 StackDump main RunSoSimple RunSo main_ver \
      stack fastcall big_thing big_thing_cxx longjmp fork sysenter

all: $(OBJS) $(LIBS) $(EXECS)

%.so: %.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

ImageSection: ImageSection.c
	objcopy -I binary -O elf32-i386 -B i386 ImageSection.c ImageSource.o
	$(CC) $(CFLAGS) -o ImageSection $< ImageSource.o

ManualNameMangling: ManualNameMangling.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

pthread_mul: pthread.c
	$(CC) $(CFLAGS) -lpthread $< -o $@

ab: a.o b.o
	$(LD) -m elf_i386 $? -e main -o $@

HelloWorld: HelloWorld.c
	$(CC) -static --verbose -fno-builtin $< -o $@

TinyHelloWorld: TinyHelloWorld.c
	$(CC) $(CFLAGS) -c -fno-builtin $<
	$(LD) -static -T TinyHelloWorld.lds -m elf_i386 -o $@ $@.o

target: target.c
	$(CC) -lbfd -o $@ $<

SectionMapping: SectionMapping.c
	$(CC) $(CFLAGS) -static $< -o $@

Program%: Program%.c Lib.so
	$(CC) $(CFLAGS) ./Lib.so -o $@ $<

main: main.c b1.c b2.c a1.so a2.so
	$(CC) $(CFLAGS) $(MYLDFLAGS) -fPIC -shared -o b1.so b1.c a1.so
	$(CC) $(CFLAGS) $(MYLDFLAGS) -fPIC -shared -o b2.so b2.c a2.so
	$(CC) $(CFLAGS) $(MYLDFLAGS) $< b1.so b2.so -o $@

RunSoSimple: RunSoSimple.c
	$(CC) $(CFLAGS) -ldl $< -o $@

RunSo: RunSo.c
	$(CC) $(CFLAGS) -ldl $< -o $@

lib.so: lib_v1.c
	$(CC) $(CFLAGS) -fPIC -shared -Wl,--version-script,lib_v1.ver $< -o $@

main_ver: main_ver.c lib.so
	$(CC) $(CFLAGS) $(MYLDFLAGS) ./lib.so $< -o $@
#	$(CC) $(CFLAGS) -fPIC -shared -Wl,--version-script,lib_v0.ver lib_v0.c -o lib.so

stack: stack.c
	$(CC) $(CFLAGS) -g -o $@ $<

fastcall: fastcall_a.o fastcall_b.o
	$(CC) $(CFLAGS) -g -o $@ $^

big_thing_cxx: big_thing_cxx.cpp
	$(CXX) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS) $(LIBS) $(EXECS) *.o *.so


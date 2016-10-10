CFLAGS=-m32 -fno-stack-protector
CXXFLAGS=-m32
LDFLAGS=
OBJS=SimpleSection.o CustonSection.o WeakSymbol.o
EXECS=ImageSection SpecialSymbol ManualNameMangling WeakReference pthread \
      pthread_mul ab HelloWorld TinyHelloWorld target SectionMapping \
      HeapSize

all: $(OBJS) $(EXECS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%: %.o
	$(CC) $< -o $@

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

.PHONY: clean
clean:
	rm -f $(OBJS) $(EXECS) *.o

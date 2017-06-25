# ACTION.suffix

%.o: %.C
	$(COMPILE.C) $(OUTPUT_OPTION) $<

%: %.o
	$(LINK.O) $^ $(LOADLIBS) $(LDLIBS) -o $@

COMPILE.C = $(COMPILE.cc)
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
CXX = g++
OUTPUT_OPTION = -o $@

LINK.o = $(CC) $(LDFLAGS) $(TARGET_ARCH)
CC = gcc

PROGRAMS := dict_use seamlessone seamlesstwo seamlessthree seamlessfour print_dispatch  \
	print_vtable_use simple_cplx cetology
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS = 
VPATH = ../ch10

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS)

dict_use: dict.o keyval.o
dict_use print_vtable_use simple_cplx cetology: CFLAGS += `pkg-config --cflags glib-2.0`
dict_use print_vtable_use simple_cplx cetology: LDLIBS += `pkg-config --libs   glib-2.0`

seamlessone seamlesstwo: CFLAGS += --ms-extensions
seamlessone seamlesstwo seamlessthree seamlessfour: LDLIBS += -lm

print_vtable_use: print_vtable.o

simple_cplx: CFLAGS += `pkg-config --cflags gsl`
simple_cplx: LDLIBS += `pkg-config --libs   gsl`
simple_cplx: complex.o

cetology: fstr.o string_utilities.o
cetology: CFLAGS += -I../ch10

clean:
	@rm -f $(PROGRAMS) *.o

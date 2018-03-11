PROGRAMS := sum_to_nan varad double_printf double_printf1 times_table \
	safe_sum foreach vectorize boxes init_zero array_init \
	papersize errortuple olden_varargs macro_varargs ideal amort_use \
	show_tree charct
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS = 

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS)

amort_use: amort_interface.o amortize.o
amort_use: LDFLAGS += -lm

show_tree: process_dir.o

charct: string_utilities.o unictr.o process_dir.o
charct: CFLAGS += `pkg-config --cflags glib-2.0`
charct: LDLIBS += `pkg-config --libs   glib-2.0`

clean:
	@rm -f $(PROGRAMS) *.o

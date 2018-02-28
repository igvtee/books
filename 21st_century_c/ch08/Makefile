PROGRAMS := curly sizesof preprocess blankcheck extern constchange \
	    constchange2 conststruct iggy_pop_detector constfusion
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS = 

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS) def_macro.txt

def_macro.txt:
	@echo "" | $(CC) -dM -E -xc - > def_macro.txt

extern: extern1.o extern2.o

extern_init: extern.o extern3.o extern4.o
	@$(CC) $^ -o $@

clean:
	@rm -f $(PROGRAMS) *.o

PROGRAMS := stddev stddev_bugged glist dict_test
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS = 
LDLIBS = -lm

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS)

glist dict_test: CFLAGS += `pkg-config --cflags glib-2.0`
glist dict_test: LDLIBS += `pkg-config --libs   glib-2.0`

dict_test: dict.o keyval.o
dict_test dict.o keyval.o : CFLAGS += -O0 -fprofile-arcs -ftest-coverage

clean:
	@rm -f $(PROGRAMS) *.o *.gcda *.gcno *.gcov

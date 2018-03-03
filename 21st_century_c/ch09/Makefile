PROGRAMS := sadstrings getstrings asprintf print sasprintf count_lines \
	    unicode
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS = 

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS)

asprintf: CFLAGS += -DTest_asprintf

unicode: CFLAGS += `pkg-config --cflags glib-2.0`
unicode: LDLIBS += `pkg-config --libs   glib-2.0`

unicode: string_utilities.o

clean:
	@rm -f $(PROGRAMS) *.o

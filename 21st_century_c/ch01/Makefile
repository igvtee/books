PROGRAMS := erf getenv gsl_erf
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS =

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS)

erf: LDLIBS += -lm

gsl_erf: LDLIBS += `pkg-config --libs gsl`

clean:
	@rm -f $(PROGRAMS)

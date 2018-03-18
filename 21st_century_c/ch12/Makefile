PROGRAMS := openmp_wc mapreduce_wc openmp_factors openmp_atoms pthread_factors c_factors \
	    c_primes
OBJECTS =
CFLAGS = -g -Wall -O3
LDFLAGS =
VPATH = ../ch10

.PHONY: all clean
all: $(PROGRAMS) $(OBJECTS)

openmp_wc mapreduce_wc openmp_factors openmp_atoms: CFLAGS += `pkg-config --cflags glib-2.0` \
							      -fopenmp
openmp_wc mapreduce_wc openmp_factors openmp_atoms: LDLIBS += `pkg-config --libs   glib-2.0`

openmp_wc mapreduce_wc: string_utilities.o
openmp_wc mapreduce_wc: CFLAGS += -I../ch10

pthread_factors: CFLAGS += -fopenmp
c_factors c_primes: CFLAGS += -pthread -latomic
c_primes: CFLAGS += -lm

clean:
	@rm -f $(PROGRAMS) *.o

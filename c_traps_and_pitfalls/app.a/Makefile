CFLAGS += -Wall

program := printf printf1 printf2 printf3 printf4 printf5 \
	   printf6 printf7 printf8 printf9 printf10 printf11 \
	   printf12 printf13 printf14 printf15

.PHONY: all clean
all: $(program)

printf8: CFLAGS += -lm

clean:
	@rm -f $(program)

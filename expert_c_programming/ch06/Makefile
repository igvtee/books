program := main hello hello2 hello3 hello4 hello5 hello6 \
	stack_addr frame setjmp

.PHONY: all clean
all: $(program)

hello6: hello5.c
	$(CC) -g $^ -o $@

clean:
	@rm -f $(program)

VPATH = src include
CPPFLAGS = -I include

count_words: counter.o lexer.o -lfl
count_words.o: counter.h
counter.o: counter.h lexer.h
lexer.o: lexer.h

#%.o: %.c
#	$(COMPILE.c) $(OUTPUT_OPTION) $<

#%.c: %.l
#	@$(RM) $@
#	$(LEX.l) $< > $@

#%: %.c
#	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

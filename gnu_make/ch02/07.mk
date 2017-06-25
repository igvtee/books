VPATH = src include
CPPFLAGS = -I include

depend: count_words.c lexer.c counter.c
	$(CC) -M $(CPPFLAGS) $^ > $@
include depend

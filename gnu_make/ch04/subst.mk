# $(subst search-string,replace-string,text)
sources := count_words.c counter.c lexer.c
objects := $(subst .c,.o,$(sources))

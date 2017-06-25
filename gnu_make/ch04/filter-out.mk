# $(filter-out pattern,text)
# find out not *.h files
all_source := count_words.c counter.c lexer.l counter.h lexer.h
to_compile := $(filter-out %.h, $(all_source))

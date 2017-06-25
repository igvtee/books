# $(call has-duplicates, word-list)
has-duplicates = $(filter \
	$(words $1), \
	$(words $(sort $1)))

data := a b c d e
dupdata := a a b c d

dup:
	# $(call has-duplicates, $(data))
	# $(call has-duplicates, $(dupdata))

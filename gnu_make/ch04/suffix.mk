# $(suffix name...)
# $(call same-suffix, file-list)
same-suffix = $(filter 1, $(words $(sort $(suffix $1))))
date := a.c b.c d.c

suffix:
	# $(call same-suffix, $(data))

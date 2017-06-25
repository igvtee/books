DF = df
AWK = awk

free-space := $(DF) . | $(AWK) 'NR == 2 { print $$4 }'

.PHONY: all
all:
	$(free-space)

AWK ?= awk
SORT ?= sort
PR ?= pr

# help - The default goal
.PHONY: help
help:
	@ $(MAKE) -f 05.mk --print-data-base --question | \
	$(AWK) '/^[^.%][-A-Za-z0-9_]*:/	\
		{ print substr($$1, 1, length($$1)-1)}' | \
	$(SORT) | \
	$(PR) --omit-pagination --width=80 --columns=4

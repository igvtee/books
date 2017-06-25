# $(dir list...)
source-dirs := $(sort \
	$(dir \
	$(shell find . -name '*.c')))

# $(call source-dirs, dir-list)
source-dirs = $(sort \
	$(dir \
	$(shell find $1 -name '*.c')))

all:
	# $(source-dirs)

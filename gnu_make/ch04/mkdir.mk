REQUIRED_DIRS := FOO BAR
_MKDIRS := $(shell for d in $(REQUIRED_DIRS); \
	do \
		[[ -d $dd ]] || mkdir -p $$d; \
	done)

.PHONY: mkdir
mkdir:
	# mkdir $(REQUIRED_DIRS)
	$(_MKDIRS)

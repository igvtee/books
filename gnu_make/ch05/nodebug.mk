sources := $(wildcard *.mk)

.PHONY: no_debug_printf
no_debug_printf: $(sources)
	! grep --line-number '"debug:' $^

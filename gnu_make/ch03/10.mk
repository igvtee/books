.PHONY:all

ifneq "$(MAKECMDGOALS)" "clean"
  -include $(subst .xml,.d,$(xml_src))
endif

all:
	@echo MAKE_VERSION:$(MAKE_VERSION)
	@echo CURDIR:$(CURDIR)
	@echo MAKEFILE_LIST:$(MAKEFILE_LIST)
	@echo MAKECMDGOALS:$(MAKECMDGOALS)
	@echo "$(.VARIABLES)" | tr ' ' '\n' | grep MAKEF

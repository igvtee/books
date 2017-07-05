MACHINE := $(shell uname -smo | sed 's/ /-/g')
include $(MACHINE)-defines.mk

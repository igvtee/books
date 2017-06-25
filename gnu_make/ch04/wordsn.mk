# $(words n,text)
version_list := $(subst ., ,$(MAKE_VERSION))
minor_version := $(word 2, $(version_list))

current := $(word $(words $(MAKEFILE_LIST)), $(MAKEFILE_LIST))

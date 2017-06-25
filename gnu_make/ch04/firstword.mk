# $(firstword text)
version_list := $(subst ., ,$(MAKE_VERSION))
major_version := $(firstword $(version_list))

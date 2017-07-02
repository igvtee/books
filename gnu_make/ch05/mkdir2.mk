# $(call make-dir, directory)
make-dir = $(if $(wildcard $1),,$(MKDIR) -p $1)

$(config): $(config_template)
	$(call make-dir, $(dir $@))
	$(M4) $^ > $@

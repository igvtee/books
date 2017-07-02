# the last line is wrong. it will execute before target
# $(call strip-program, file)
define strip-program
  strip $1
endef

complex_script:
	$(CC) $^ -o $@
ifdef STRIP
	$(call strip-program, $@)
endif
	$(if $(PACK), upx --best $@)
	$(warning Final size: $(shell ls -s $@))

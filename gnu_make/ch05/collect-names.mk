# $(call collect-names, root-dir, dir-list, suffix1-opt, suffix2-opt)
define collect-names
  echo Making $@ from directory list...
  cd $1; \
  shopt -s nullglob; \
  for f in $(foreach file,$2,'$(file)'); do \
    files=( $$f$(if $3,/*.{$3$(if $4,$(comma)$4)}) ); \
    if (( $${#files[@]} > 0 )); \
    then \
      printf '"%s"\n' $${files[@]}; \
    else :; fi;
  done
endef

%.images:
	@$(call collect-names,$(SOURCE_DIR),$^,gif,jpeg) > $@

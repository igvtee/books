compile_all: $(FILE_LIST)
	$(JAVA) @$<

.INTERMEDIATE: $(FILE_LIST)
$(FILE_LIST):
	shopt -s nullglob; \
	for d in $(source_dirs); \
	  echo $$d/*.java; \
	done > $@

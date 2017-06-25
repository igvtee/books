# $(call process-xml,project-project-prefix,file-name)
define process-xml
  $($1_LIB)/xmlto -o $($1_BIN)/xml/$2 $($1_src)/xml/$2
endef

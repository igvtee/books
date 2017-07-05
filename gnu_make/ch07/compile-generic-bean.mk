EJB_TMP_JAR = $(TMPDIR)/temp.jar

# $(call compile-generic-bean, bean-type, jar-name,
# 	bean-files-wildcard, manifest-name-opt)
define compile-generic-bean
  $(RM) $(dir $(META_INF))
  $(MKDIR) $(META_INF)
  $(if $(filter %.xml %.xmi, $3), \
    cp $(filter %.xml %.xmi, $3) $(META_INF))
  $(call compile-$1-bean-hook,$2)
  cd $(OUTPUT_DIR) && \
  $(JAR) -cf0 $(EJB_TMP_JAR) \
    $(call jar-file-arg,$(META_INF)) \
    $(call bean-classes,$3)
  $(call $1-compile-command,$2)
  $(call create-manifest,$(if $4,$4,$2),,)
endef

# $(call compile-websphere-bean-hook, file-list)
define compile-websphere-bean-hook
  cp $(filter %.xsl, $1) $(META_INF)
endef

# $(call jar-file-arg, file-name)
define jar-file-arg
  -C "$(patsubst %/,%,$(dir $1))" $(notdir $1)
endef

# $(call bean-classes, bean-files-list)
define bean-classes
  $(subst $(SOURCE_DIR)/,, \
    $(filter %Interface.class %Home.class, \
      $(subst .java,.class,$1)))
endef

define weblogic-compile-command
  cd $(TMPDIR) && \
    $(JVM) weblogic.ejbc -compiler $(EJB_JAVAC) $(EJB_TMP_JAR) $1
endef

# $(call compile-weblogic-bean, jar-name,
#	bean-files-wildcard, manifest-name-opt)
define compile-weblogic-bean
  $(call compile-generic-bean,weblogic,$1,$2,$3)
endef

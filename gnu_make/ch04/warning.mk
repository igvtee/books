# $(warning text)
$(if $(wildcard $(JAVAC)),, \
	$(warning The java compiler variable, JAVAC ($(JAVAC)), \
	is not properly set.))

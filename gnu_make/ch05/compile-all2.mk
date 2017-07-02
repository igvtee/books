compile_all:
	$(JAVAC) $(wordlist 1, 499, $(all-source-files))
	$(JAVAC) $(wordlist 500, 999, $(all-source-files))
	$(JAVAC) $(wordlist 1000, 1499, $(all-source-files))

compile_all:
	$(JAVAC) $(filter a%, $(all-source-files))
	$(JAVAC) $(filter b%, $(all-source-files))

compile_all:
	$(foreach 1,a b c d e ..., \
	  $(if $(filter $1%, $(all-source-files)), \
	    $(JAVAC) $(filter $1%, $(all-source-files));))

compile_all:
	$(foreach 1,a b c d e ..., \
	  $(if $(filter $1%, $(all-source-files)), \
	    $(eval \
	      $(shell \
	        $(JAVAC) $(filter $1%, $(all-source-files));))))

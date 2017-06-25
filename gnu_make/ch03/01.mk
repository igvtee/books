LIBRARY = libio.a # LIBRARY value with space at the end
missing_file:
	touch $(LIBRARY)
	ls -l | grep '$(LIBRARY)'

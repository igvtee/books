# $(patsubst search-pattern,replace-pattern,text)
strip-trailing-slash = $(patsubst %/,%,$(directory-path))

# $(variable:search=replace)

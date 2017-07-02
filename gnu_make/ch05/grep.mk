# prevent hang if RAW_DATA_FILES is empty
$(DATA_FILE): $(RAW_DATA)
	grep pattern $(RAW_DATA_FILES) /dev/null > $@

all:
	for i in *.c; do cp $$i $${i%%.c}.bkup; done

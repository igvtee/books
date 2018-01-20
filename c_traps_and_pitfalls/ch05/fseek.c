while (fread((char *) &rec, sizeof(rec), 1, fp) == 1) {
	do something to rec
	if (rec must be rewritten) {
		fseek(fp, -(long)sizeof(rec), 1);
		fwrite((char *)&rec, sizeof(rec), 1, fp);
		fseek(fp, 0L, 1);
	}
}

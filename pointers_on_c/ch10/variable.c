struct VARIABLE {
	enum {INT, FLOAT, STRING} type;
	union {
		int i;
		float f;
		char *s;
	} value;
};

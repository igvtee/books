/* wrong */
struct SELF_REF1 {
	int a;
	struct SELF_REF1 b;
	int c;
};

/* ok */
struct SELF_REF2 {
	int a;
	struct SELF_REF2 *b;
	int c;
};

/* wrong */
typedef struct {
	int a;
	SELF_REF3 *b;
	int c;
} SELF_REF3;

/* ok */
typedef struct SELF_REF3_TAG {
	int a;
	struct SELF_REF3_TAG *b;
	int c;
} SELF_REF3;


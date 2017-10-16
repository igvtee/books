#include <time.h>

struct PHONE {
	int area_code;
	int exchange;
	int station_number;
};

struct CALL {
	time_t time;
	struct PHONE from;
	struct PHONE to;
	struct PHONE bill;
};

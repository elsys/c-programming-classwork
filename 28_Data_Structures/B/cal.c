#include <stdio.h>

struct calendar_t {
	int events_count[52];
};

int* events_per_month(struct calendar_t);

int main() {

	return 0;
}

int* events_per_month(struct calendar_t cal) {
	int per_month[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	for (int i = 0; i < 52; i++) {
		per_month[i / 4] += cal.events_count[i];
	}

	return per_month;
}

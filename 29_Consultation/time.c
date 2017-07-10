#include <stdio.h>

struct time_t {
	int hour, minutes;
};

int is_lunch_break(struct time_t);


int is_lunch_break(struct time_t time) {
	// 12:15 - 14:23
	if(time.hour > 12 && time.hour < 14) {
		return 1;
	}
	
	if(time.hour == 12 && time.minutes >= 15) {
		return 1;
	}

	if(time.hour == 14 && time.minutes <= 23) {
		return 1;
	}
	
	return 0;
}

int main() {
	struct time_t t = { 12, 15 };
	
	struct time_t t2 = {
		.hour = 14,
		.minutes = 23
	};
	
	struct time_t t3;
	t3.hour = 13;
	t3.minutes = 20;
	
	struct time_t t4 = {15, 40};
	
	
	printf("12:15: %d\n", is_lunch_break(t));
	printf("14:23: %d\n", is_lunch_break(t2));
	printf("13:20: %d\n", is_lunch_break(t3));
	printf("15:40: %d\n", is_lunch_break(t4));
	
	return 0;
}








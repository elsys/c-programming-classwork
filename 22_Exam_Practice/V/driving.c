#include <stdio.h>

struct driving_license_t {
	char categories[10];
	int is_master;
};

int can_drive(struct driving_license_t, char[3]);

int main() {

	return 0;
}

int can_drive(struct driving_license_t license, char car[3]) {
	char car_cat = car[0];
	int car_num = 0;
	
	if (car[1] != '\0') {
		car_num = car[1] - '0';
	}		

	for(int i = 0; i < 10; i++) {
		if (license.categories[i] == car_cat) {
			if (car_num <= 3) return 1;		
			else { return license.is_master; }
		}
	}

	return 0;
}







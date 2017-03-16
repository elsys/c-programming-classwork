#include <stdio.h>

#define BIKE_SIZE_S 1
#define BIKE_SIZE_M 2
#define BIKE_SIZE_L 3

#define BIKESHOP_CAPACITY 10

struct bike_t {
	float tire_size;
	int gears_count;
	char manufacturer[51];
	char model[16];
	int frame_size;
	float cost;
};

struct bikeshop_t {
	struct bike_t bikes[BIKESHOP_CAPACITY];
	int count;
};

struct bikeshop_t init_empty_bikeshop() {
	struct bikeshop_t result = {
		.count = 0
	};
	return result;
}

struct bikeshop_t add_bike(struct bike_t, struct bikeshop_t);

int main() {
	struct bike_t encho_bike = {
		.tire_size = 26,
		.gears_count = 10,
		.manufacturer = "Shockblaze",
		.model = "TA2016",
		.frame_size = BIKE_SIZE_L,
		.cost = 1000.0,
	};
	struct bikeshop_t bikeshop = init_empty_bikeshop();
	printf("Bikes in bikeshop: %d\n", bikeshop.count);
	
	bikeshop = add_bike(encho_bike, bikeshop);
	printf("Bikes in bikeshop: %d\n", bikeshop.count);
	return 0;
}

struct bikeshop_t add_bike(struct bike_t bike, struct bikeshop_t bikeshop) {
	if(BIKESHOP_CAPACITY == bikeshop.count) {
		return bikeshop;
	}
	
	bikeshop.bikes[++bikeshop.count] = bike;
	return bikeshop;
}


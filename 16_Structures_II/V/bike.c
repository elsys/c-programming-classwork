#include <stdio.h>
#include <string.h>

struct bike_t {
	int tire_size;
	int gears;
	char brand[50];
	char model[15];
	char frame_size;
	float price;
};

struct bikeshop_t {
	int capacity;
	int current_bikes;
	struct bike_t bikes[50];
};

void print_bike(struct bike_t);
struct bikeshop_t add_bike(struct bikeshop_t, struct bike_t);
float avrg_bike_price(struct bikeshop_t);

int main() {

	struct bike_t bicycle;
	
	bicycle.tire_size = 27;
	bicycle.gears = 21;
	strcpy(bicycle.brand, "Scott");
	strncpy(bicycle.model, "Down", 15);
	// bicycle.brand = "Scott"; <-- this is not wokring!!!
	//bicycle.model = "Down";
	bicycle.frame_size = 'M';
	bicycle.price = 1249.99;

	print_bike(bicycle);

	struct bikeshop_t bikeshop;
	bikeshop.capacity = 50;
	bikeshop.current_bikes = 0;

	bikeshop = add_bike(bikeshop, bicycle);

	printf("%d\n", bikeshop.current_bikes);
	print_bike(bikeshop.bikes[0]);	

	return 0;
}

float avrg_bike_price(struct bikeshop_t shop) {
	float sum = 0;

	for (int i = 0; i < shop.current_bikes; i++) {
		sum = sum + shop.bikes[i].price;
	}	

	return sum / shop.current_bikes;
}

void print_bike(struct bike_t bike) {
	printf("Tires: %d\nGears: %d\nBrand: %s\nModel: %s\nFrame Size: %c\nPrice: %f\n", bike.tire_size, bike.gears, bike.brand, bike.model, bike.frame_size, bike.price);
}

struct bikeshop_t add_bike(struct bikeshop_t shop, struct bike_t bike_to_add) {
	if (shop.current_bikes < shop.capacity) {
		shop.bikes[shop.current_bikes] = bike_to_add;
		shop.current_bikes++;
	}
	
	return shop;
}







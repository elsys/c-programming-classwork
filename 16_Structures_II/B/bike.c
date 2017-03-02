#include <stdio.h>

struct bike_t {
	int tire_size;
	int gears;
	char brand[50];
	char model[15];
	char frame_size;
	float price;
};

struct bikeshop_t {
	int total_bikes;
	int max_bikes;
	struct bike_t bikes[50];
};

struct bike_t read_bike();
void print_shop(struct bikeshop_t);
void print_bike(struct bike_t);
struct bikeshop_t add_bike(struct bikeshop_t, struct bike_t);
float avrg_bike_price(struct bikeshop_t);
 
int main() {
	char c;
	scanf("%c", &c);
	printf("%c", c);

	struct bike_t bicycle;
	scanf("%d %d %s %s %c %f", &bicycle.tire_size, &bicycle.gears, bicycle.brand, bicycle.model, &bicycle.frame_size, &bicycle.price);

	print_bike(bicycle);

	struct bikeshop_t bikeshop;
	bikeshop.total_bikes = 0;
	bikeshop.max_bikes = 50;

	bikeshop = add_bike(bikeshop, bicycle);
	
	print_bike(bikeshop.bikes[0]);
	printf("%d", bikeshop.total_bikes);

	return 0;
}

void print_bike(struct bike_t bike) {
	printf("Tires: %d\nGears: %d\nBrand: %s\nModel: %s\nFrame Size: %c\nPrice: %f\n", bike.tire_size, bike.gears, bike.brand, bike.model, bike.frame_size, bike.price);
}

struct bikeshop_t add_bike(struct bikeshop_t shop, struct bike_t bike) {
	if (shop.total_bikes < shop.max_bikes) {
		shop.bikes[shop.total_bikes] = bike;
		shop.total_bikes++;	
	}

	return shop;
}

float avrg_bike_price(struct bikeshop_t shop) {
	float total_price = 0;

	for (int i = 0; i < shop.total_bikes; i++) {
		total_price = total_price + shop.bikes[i].price;
	}

	return total_price / shop.total_bikes;
}







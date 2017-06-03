#include <stdio.h>
#include <stdlib.h>

struct car_t {
	float engine;
	int hp;
	int door_count;
};

int main() {
	struct car_t *ptr = malloc(sizeof(struct car_t));

	ptr.engine;
	*(ptr)->engine;

	return 0;
}

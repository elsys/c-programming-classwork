#include <stdio.h>
#include <stdlib.h>

struct vector_t {
	int count;
	int size;
	int *arr;
};

struct vector_t init();
void add_last(struct vector_t*, int);
int last(struct vector_t);

int main() {

	struct vector_t vector = init();
	add_last(&vector, 10);
	printf("%d\n", last(vector));

	add_last(&vector, 20);
	add_last(&vector, 30);
	add_last(&vector, 40);

	printf("%d\n", last(vector));

	return 0;
}

int last(struct vector_t vector) {
	return vector.arr[vector.count-1];
}

void add_last(struct vector_t *vector, int item) {
	if (vector->count == vector->size) {
		vector->size *= 2;
		vector->arr = realloc(vector->arr, vector->size * sizeof(int)); 
	}
	vector->arr[vector->count] = item;
	vector->count++;
}

struct vector_t init() {
	struct vector_t result;
	result.count = 0;
	result.size = 1;
	result.arr = malloc(sizeof(int));

	return result;
}


#include <stdio.h>
#include <stdlib.h>

struct vector_t {
	int size;
	int capacity;
	int *arr;
};

struct vector_t init();
void add_last(struct vector_t*, int);
int last(struct vector_t);
int pop(struct vector_t*);

int main() {
	struct vector_t v = init();
	add_last(&v, 5);
	add_last(&v, 10);
	
	pop(&v);

	printf("%d\n", last(v));
		
	return 0;
}

int pop(struct vector_t *vector) {
	vector->size--;
	return vector->arr[vector->size];	
}

int last(struct vector_t vector) {
	if (vector.size == 0) {
		// Empty; return error!
	}
	return vector.arr[vector.size - 1];
}

void add_last(struct vector_t *vector, int val) {
	if (vector->size == vector->capacity) {
		vector->capacity *= 2;
		vector->arr = realloc(vector->arr, vector->capacity * sizeof(int));
	}

	vector->arr[vector->size++] = val;
} 

struct vector_t init() {
	struct vector_t vector;
	vector.size = 0;
	vector.capacity = 4;
	vector.arr = malloc(vector.size * sizeof(int));

	return vector;
}










#include <stdio.h>

void by_two(int *arr, int size);
void print(int *arr, int size);
void product(int *arr, int size, int *prod);
int *last_index_of(int*, int, int);
int copy_only_positive(int *arr, int size, int *positives);

int main() {

	int array[] = {1, -2, 3, 4};

	print(array, 4);
	by_two(array, 4);
	print(array, 4);	
	
	int prod;
	product(array, 4, &prod);
	printf("%d\n", prod);

	int *elem = last_index_of(array, 4, 6);

	if (elem != NULL) {
		printf("%d\n", *elem);
	}
	else {
		printf("No such element");
	}
	
	int positive_arr[20]; 

	int positive_size = copy_only_positive(array, 4, positive_arr);

	print(positive_arr, positive_size);

	return 0;
}

int copy_only_positive(int *arr, int size, int *positives) {
  	int positive_i = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) {
			positives[positive_i++] = arr[i];
		}
	}

	return positive_i;
}

int *last_index_of(int *arr, int size, int item) {
	int pos = -1;
	for(int i = 0; i < size; i++) {
		if (arr[i] == item) {
			pos = i;	
		}
	}

	if (pos == -1) { return NULL; }
	return arr + pos;
}

void product(int *arr, int size, int *prod) {
	if (size == 0) { return; }
	*prod = 1;
	for(int i = 0; i < size; i++) {
		*prod *= arr[i];
	}
}

void by_two(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		*(arr + i) = arr[i] * 2;
	}
}

void print(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}








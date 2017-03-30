#include <stdio.h>

void swap(int*, int*);
void rotr(int*, int*, int*);
int *find(int*, int, int);
void get_min_max(int*, int*, int*, int);

int main() {

	int a = 10;
	int b = 4;
	int c = 7;

	swap(&a, &b);

	printf("%d %d\n", a, b);

	rotr(&a, &b, &c);

	printf("%d %d %d\n", a, b, c);

	int arr[] = {1, 2, 3, 17, 22, 36};

	int *element = find(arr, 6, 10);
	
	if (element != NULL) {	
		printf("%d", *element);
	}
	else {
		printf("No such element\n");
	}

	
	// We need ** in order for this to work
	//int *u = NULL , *v = NULL;
	
	//get_min_max(arr, u, v, 6);

	//printf("%d %d\n", *u, *v); 

	return 0;
}

void get_min_max(int *arr, int *min, int *max, int size) {
	if (size == 0) {
		min = NULL;
		max = NULL;
		return;
	}
	
	min = arr;
	max = arr;
	
	for (int i = 0; i < size; i++) {
		if (arr[i] > *max) {
			max = &arr[i];
		}

		if (*min > arr[i]) {
			min = &arr[i];
		}
	}	
}

int *find(int *haystack, int size, int needle) {
	for(int i = 0; i < size; i++) {
		if (needle == *(haystack + i)) {
			return &haystack[i];
		}
	}

	return NULL;
}

void rotr(int *q, int *w, int *e) {
	int tmp = *w;
	*w = *q;
	*q = *e;
	*e = tmp;
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;	
}



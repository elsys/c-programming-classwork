#include <stdio.h>

void swap(int*, int*);
void rotr(int*, int*, int*);
int* find(int*, int, int);
void get_min_max(int*, int*, int*, int);
int print_sequence(int*, int*);

int main() {

	int a = 5;
	int b = 8;
	int c = 10;

	int arr[] = {7, 9, 10, 5, 12, 16};

	swap(&a, &b);

	printf("%d %d", a, b);	
	
	rotr(&a, &b, &c);

	printf("%d %d %d\n", a, b, c);

	int *element = find(arr, 6, 11);

	if (element != NULL) {
		printf("%d\n", *element);
	}
	else {
		printf("No such element found\n");
	}

	int p, q;

	get_min_max(arr, &p, &q, 6);
	
	//if (p == NULL) {
	//	printf("No min & max\n");
	//}
	//else {
		printf("%d %d\n", p, q);
	//}

	int printed_elements = print_sequence(&arr[0], &arr[3]);

	printf("%d\n", printed_elements);
	
	return 0;
}

int print_sequence(int *start, int *end) {
	int printed = 0;
	for(int *i = start; i != end; i++, printed++) {
		printf("%d\n", *i);
	}

	return printed;
}

void get_min_max(int *array, int *min, int *max, int size) {
	if (size == 0) {
		min = NULL;
		max = NULL;
		return;	
	}
	
	*min = *array;
	*max = *array;
	
	for (int i = 1; i < size; i++) {
		if (*min > array[i]) {
			*min = array[i];
		}

		if (*max < array[i]) {
			*max = array[i];
		} 		
	}	
}

int *find(int *haystack, int size, int needle) {
	for(int i = 0; i < size; i++) {
		if(*(haystack+i) == needle) {
			return &haystack[i];
		}
	}

	return NULL;
}

void rotr(int *x, int *y, int *z) {
	int tmp = *x;
	*x = *z;
	*z = *y;
	*y = tmp;	
}

void swap(int *num1, int *num2) {
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;	
}

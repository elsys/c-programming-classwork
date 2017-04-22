#include <stdio.h>

int is_between(int*, int*, int*);
void rotate_right(int*, int*);
int *rotate(int*, int*, int*);

int main() {

	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};	
	
	int x = 5;

	printf("%d\n", is_between(&arr[0], &arr[1], &arr[2]));
	printf("%d\n", is_between(&arr[0], &x, &arr[2]));

	for(int i = 0; i < 8; i++) {
		printf("%d\n", arr[i]);
	}

	rotate(&arr[0], &arr[2], &arr[4]);

	for(int i = 0; i < 8; i++) {
		printf("%d", arr[i]);
	}
	
	printf("\n");

	return 0;
}

int *rotate(int *first, int *middle, int *last) {
	if (!is_between(first, middle, last)) { return NULL; }

	for(int i = 0; i < (last-middle) + 1; i++) {
		rotate_right(first, last);
	}
	
	return first;
}

void rotate_right(int *start, int *end) {
	int tmp = *end;

	for(int *i = end; i > start; i--) {
		*(i) = *(i - 1);
	}

	// 1, 2, 3, 4, 5, 6
	// 1, 2, 3, 4, 5, 5
	// 1, 2, 3, 4, 4, 5
	// 1, 2, 3, 3, 4, 5
	// 1, 2, 2, 3, 4, 5
	// 1, 1, 2, 3, 4, 5
	
	*start = tmp;			
	// 6, 1, 2, 3, 4, 5
}

int is_between(int *first, int *middle, int *last) {
	return first < middle && middle < last;	
}









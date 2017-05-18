#include<stdio.h>


#include <stdlib.h>

void a(int *arr) {
	//int *arr2 = malloc(10 * 4);
}

int main() {

	int *arr = malloc(10 * sizeof(int));

	if (arr == NULL) { /* There is not enough memory */ }

	for (int i = 1; i < 11; i++) {
		arr[i - 1] = i;
		printf("%d\n", arr[i-1]);
	}

	//free(arr);

	return 0;
}

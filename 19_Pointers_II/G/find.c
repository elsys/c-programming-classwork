

#include <stdio.h>

int* find(int *haystack, int size, int needle) {
	for(int i = 0; i < size; i++) {
		if(haystack[i] == needle) {
			return &haystack[i];
		}
	}
	return NULL;
}

int main() {

	int arr[4] = {1, 2, 3, 4};

	printf("%d\n", find(arr, 4, 9) == NULL);
	printf("%d\n", find(arr, 4, 1) == NULL);
	printf("%d\n", find(arr, 4, 4) == NULL);

	return 0;
}

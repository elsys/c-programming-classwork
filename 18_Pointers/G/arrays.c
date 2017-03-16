#include <stdio.h>

int main() {
	int arr[5] = {5, 4, 3, 2, 1};

	
	printf("%p\n", (void*) arr);
	printf("%d\n", *arr);
	printf("%d\n", *(arr + 4));
	printf("%d\n", arr[0]);
	printf("%p\n", ++arr);
	return 0;
}

#include <stdio.h>

int main() {
	int arr[5] = {5, 4, 3, 2, 1};

	for(int *ptr = arr; ptr != arr + 5; ptr++) {
		printf("%d ", *ptr);
	}
	return 0;
}

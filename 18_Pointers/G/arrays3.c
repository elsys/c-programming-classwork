#include <stdio.h>

int main() {
	int arr[5] = {1, 2, 3, 4, 5};

	printf("%d\n", arr[3]);
	printf("%d\n", 3[arr]);
	printf("%d\n", *(arr + 3));
	printf("%d\n", *(3 + arr));
	return 0;
}

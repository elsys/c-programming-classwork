

#include <stdio.h>

void swap(int *a, int *b) {
	printf("in swap, a = %d, b = %d\n", *a, *b);
	int c = *a;
	*a = *b; // a = b; will not work
	*b = c;
	printf("in swap, a = %d, b = %d\n", *a, *b);
}

int main() {
	
	int a = 4, b = 5;
	printf("Before swap\n");
	printf("a = %d, b = %d\n", a, b);

	swap(&a, &b);

	printf("After swap\n");
	printf("a = %d, b = %d\n", a, b);

	return 0;
}

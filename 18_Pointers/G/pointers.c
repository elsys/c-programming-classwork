#include <stdio.h>

int main() {
	int sample = 5;
	int *ptr;

	ptr = &sample;
	
	printf("%d\n", sample);
	printf("%d\n", *ptr);
	printf("%p\n", (void*) &sample);
	printf("%p\n", (void*) ptr);

	return 0;
}

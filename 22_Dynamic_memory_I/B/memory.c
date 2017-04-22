#include <stdio.h>
#include <stdlib.h>


int sum(int a, int b) {
	int c = a + b;
	return c;
}

int main() {
	
	int x = 9;
	int y = 10;

	{
		int p = 10;
		printf("%d\n", p);
	}

	
	sum(x, y);	


	int *arr = malloc(10 * sizeof(int));
	
	if(arr == NULL) {
 		return 1;
	}

	for(int i = 0; i < 10; i++) {
		printf("%d\n", *(arr + i));
		arr[i] = i;
	}

	free(arr);
	
	arr = malloc(10 * sizeof(int));
	
	if(arr == NULL) {
 		return 1;
	}

	for(int i = 0; i < 10; i++) {
		printf("%d\n", *(arr + i));
	}

	free(arr);
	


	int size;
	scanf("%d", &size);

	char *word = malloc(size * sizeof(char));

	for(int i = 0; i < size; i++) {
		getchar();
		scanf("%c", &word[i]);
	}	

	for(int i = size - 1; i >= 0; i--) {
		printf("%c", word[i]);
	}
	printf("%s\n", word);

	free(word);
	
	return 0;
}

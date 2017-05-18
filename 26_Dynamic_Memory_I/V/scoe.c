#include <stdio.h>



#include <stdlib.h>
int main() {
	int al;


	{
		int a = 5;
		int b = 10;
		printf("%d\n", a+b);
	}
	

	int *arr = malloc(12);
	int *arr2 = malloc(10 * sizeof(int));
	//struct alabala_t *ptr = malloc( 10 * sizeof(struct alabala_t));
	char *str = malloc(20);
	float *farr = malloc(50);
		
	char ch;
	
	//char *str;
	int i = 0;
	while(EOF != scanf("%c", &ch)) {
		str[i] = ch;
		i++;
	}

	if(1) {
		int asd;

		for(int i = 0; i < 10; i++) {

		}
	}

	int first, second;
	sum(first, second);

	return 0;
}

int sum(int a, int b) {
	int result;
}

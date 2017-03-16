#include <stdio.h>

int main() {

	
	int a = 5;

//	scanf("%d", &a);
	
//	printf("%d\n", *((int*)a));

	*(&a) == a;

	int *p = &a;
	/* Трябва да има още 1 звездичкa, защото q е указател
	 * към нещо от тип int*, а не просто int т.е. той е
	 * указател към указател и затова типът му трябва да 
	 * бъде с две звездички!
	 */
	int **q = &p; 

	printf("%p\n", (void*)p);
	printf("%p\n", (void*)*q);
	printf("%d\n", *(*q));

	printf("%d\n", a);
	//printf("%p\n", (void*)p);
//	printf("%p\n", (void*)q);

	*p = 7;

	printf("%d\n", a);
	int arr[] = {100, 150, 200, 250};
//	char carr[] = {'a', '1', '7', 'c'};

	//void *point = arr;

	for (int i = 0; i < 4; i++) {
		//printf("%p\n", (void*)&carr[i]);
		//printf("%d\n", *(arr + i));
		//printf("%p\n", (void*)(point + i));
		// ^ warning pointer of void* used in arithmetics
	}

//	int *arr_p = arr;
//	char *char_p = arr;
//	double *d_p = arr;
	
//	printf("%d\n", *(arr_p + 1));
//	printf("%d\n", *(char_p + 1));
//	printf("%d\n", *(d_p + 1));
//
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(char));
//	printf("\n%p\n", (void*)&a);
//	printf("\n%p\n", (void*)p);
//	printf("\n%p\n", (void*)&p); 

	return 0;
}

#include <stdio.h>

int main() {

	int a = 5;
	int b = 20;

	int *p = &a;
	
	*p = 8;

	printf("%d\n", a);
	printf("%d\n", *p);

	scanf("%d", &a);
	printf("%d", *((int*)a));

	int arr[] = {500, 600, 700};
	char carr[] = {'a','1','y'};
	
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(double));

	int *p_arr = arr;
	char *c_arr = arr;
	double *d_arr = arr;
	
	for(int i = 0; i < 3; i++) {
		printf("%d\n", *(p_arr + i));
		printf("%d\n", *(c_arr + i));
		printf("%d\n", *(d_arr + i));
	}

	printf("%p\n", (void*)arr);
	printf("%p\n", (void*)&arr[0]);
	
	printf("%d\n", *(arr + 0));
	printf("%d\n", arr[0]);
	printf("%d\n", *(arr + 2));	

	printf("%p\n", (void*)&a);
	printf("%p\n", (void*)p);

	printf("%p\n", (void*)&p);
	
	printf("%d\n", *p);

	return 0;
}

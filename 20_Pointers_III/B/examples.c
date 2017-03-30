#include <stdio.h>
#include <string.h>

void sum(int*, int, int*);
void avrg(float*, int, float*);
int str_cmp(char*, char*);
void reverse(char*);

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	int arrSum;
	float arrAvrg;

	sum(arr, 5, &arrSum);

	printf("%d\n", arrSum);
	
	float farr[] = {1.0, 2.5, 1.5, 1.0};

	avrg(farr, 4, &arrAvrg);

	printf("%f\n", arrAvrg);
	
	char s1[] = "String";
	char s2[] = "Pesho1";
	char s3[] = "String1";

	printf("%d\n", str_cmp(s1, s2)); // 1
	printf("%d\n", str_cmp(s1, s3)); // -1

	reverse(s1);
	
	printf("%s\n", s1);
	
	return 0;
}

void reverse(char *str) {
	for(int i = 0; i < strlen(str) / 2; i++) {
		char tmp = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = tmp;
	}
}

int str_cmp(char *str1, char *str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);	
	int minLen;

	// int minLen = len1 > len2 ? len2 : len1;

	if (len1 > len2) {
		minLen = len2;
	}
	else {
		minLen = len1;
	}

	for(int i = 0; i < minLen; i++) {
		if (str1[i] > str2[i]) {
			return 1;
		}
		else if (str1[i] < str2[i]) {
			return -1;
		}
	}	

	//return len1 == len2 ? 0 : len1 > len2 ? 1 : -1;
	
	if (len1 == len2) { return 0; }
	else if (len1 > len2) { return 1; }
	else { return -1; }	
}

void avrg(float *arr, int size, float *avrg) {
	float sum = 0;
	
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}		

	*avrg = sum / size;
}

void sum(int *arr, int size, int *sum) {
	*sum = 0;

	for(int i = 0; i < size; i++) {
		*sum = *sum + arr[i];
	}
}

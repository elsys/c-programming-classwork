#include <stdio.h>
#include <stdlib.h>

int main() {

	int capacity = 4;
	int size = 0;
	char *str = malloc(capacity * sizeof(char));
	char ch;
	
	while(scanf("%c", &ch) != EOF) {
		getchar();
		if (size == capacity) {
			capacity *= 2;

			char *tmp = malloc(capacity * sizeof(char));
			for (int i = 0; i < size; i++) {
				tmp[i] = str[i];
			}
			free(str);
			str = tmp;
		}
		str[size] = ch;
		size++;
	}

	printf("%s\n", str);
	
	free(str);

	return 0;
}







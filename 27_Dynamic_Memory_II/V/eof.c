#include <stdio.h>
#include <stdlib.h>

int main() {
	char ch;
	int size = 5;
	int count = 0;
	char *str = malloc(size * sizeof(char));

	while (EOF != scanf("%c", &ch)) {
		if (count == size) {
			size *= 2;
			realloc(str, size * sizeof(char)); 
		}

		str[count] = ch;
		count++;
	}	

	printf("%s\n", str);

	return 0;
}

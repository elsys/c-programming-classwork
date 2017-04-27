#include <stdio.h>
#include <stdlib.h>

int main() {

	int size = 5;
	int count = 0;
	
	char *word = malloc(size * sizeof(char));

	char ch;
	while(scanf("%c", &ch) != EOF) {
		getchar();	
		
		word[count++] = ch;
		
		if (count == size) {
			size *= 2;

			word = realloc(word, size * sizeof(char));

			if (word == NULL) { return 1; }
		}
	}

	printf("%s\n", word);

	free(word);
	
	return 0;
}

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

			char *tmp = word;
			word = malloc(size * sizeof(char));

			if (word == NULL) { return 1; }

			for (int i = 0; i < count; i++) {
				word[i] = tmp[i];
			}

			free(tmp);
		}
	}

	printf("%s\n", word);

	free(word);
	
	return 0;
}

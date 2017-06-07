#include<stdio.h>
#include<stdlib.h>

int main() {
    char symbol;
    int size = 10;
    char *str = malloc(sizeof(char) * size);
    int count = 0;

    while(scanf("%c", &symbol) != EOF) {
        str[count++] = symbol;
        if(count == size) {
            char *buffer = malloc(sizeof(char) * size * 2);
            for(int i = 0; i < size; i++) {
                buffer[i] = str[i];
            }
            free(str);
            str = buffer;
            size = size * 2;
        }
    }
    str[count] = '\0';
    
    printf("%s\n", str);
    free(str);

    return 0;
}

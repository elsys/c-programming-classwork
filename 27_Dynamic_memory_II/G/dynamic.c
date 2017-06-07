

#include <stdio.h>
#include <stdlib.h>

int main() {
    int current_size = 20;
    char *arr = malloc(sizeof(char) * current_size);
    int current_index = 0;
    
    int c;
    while((c = fgetc(stdin)) != EOF) {
        // resize the buffer
        if(current_size == current_index) {
            current_size *= 2;
            char *temp = malloc(sizeof(char) * current_size);
            for(int i = 0; i < current_index; i++) {
                temp[i] = arr[i];
            }
            free(arr);
            arr = temp;
        }
        arr[current_index] = c;
        current_index++;
    }

    for(int i = current_index - 1; i >= 0; i--) {
        printf("%c", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>


int main() {
    int size = 5;
    // scanf("%d", &size);
    
    printf("statically allocated: %p\n", (void*) &size); 
    int *arr;
    arr = malloc(sizeof(int) * size);
    
    printf("dynamically allocated: %p\n", (void*) arr);

    free(arr);
    
    return 0;
}

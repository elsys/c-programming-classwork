
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *ptr;
    ptr = malloc(sizeof(int));
    
    *ptr = 42;
    printf("%d\n", *ptr);
    
    free(ptr);
}

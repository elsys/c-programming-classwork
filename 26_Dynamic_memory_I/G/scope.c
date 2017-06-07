

#include <stdio.h>

int main() {
    int i; // 4 bytes
    
    {
        float f = 3.14;
        char b = 'G';
        printf("%f %c\n", f, b);
    }
    // printf("%f\n", f); // causes an error
}

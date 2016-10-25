#include <stdio.h>

int main() {
    float a,b;

    scanf("%f%f", &a, &b);

    if (a == 2 * b || b == 2 * a) {
        printf("TRUE");
        return 0;
    }

    printf("FALSE");

    return 0;
}


#include <stdio.h>

int is_between(int* first, int* middle, int* last) {
    return first <= middle && middle <= last;
}

void rotate_left(int* first, int* last) {
    for(int* current = last-1; current != first-1; current--) {
        int temp = *current;
        *current = *(current+1);
        *(current+1) = temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
    rotate_left(arr, arr+3);
    printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
    return 0;
}

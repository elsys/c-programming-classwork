#include <stdio.h>

int main() {
    
    short count = 0;

    //while(++count >= 0);

    for(;count >= 0; count++);

    printf("%hd\n", count);
    printf("%hd\n", (short)(count-1));
    
    return 0;
}

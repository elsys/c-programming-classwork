#include <stdio.h>

int global;

int main() {

    int variable;
    
    for(int i = 0; i < 10; i++) {
        
    }
    // i = 5; reference error


    {
        int local_var = 5;
        local_var += 10;
        printf("%d\n", local_var);
    }
    printf("%d\n", local_var);
    
    return 0;
}

void function() {
    int local;
}

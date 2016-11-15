#include <stdio.h>

int main() {
    int target[] = {1,2,3,4};

    int cows, bulls;

    while (bulls != 4) {
        int guess;

        bulls = 0;
        cows = 0;
        int p = 3;
        
        scanf("%d", &guess);
       
        while(guess) {
            int d = guess % 10;
            for (int i = 3; i >= 0; i--) {
                if (d == target[i]) {
                    if (i == p) {
                        // bull
                        ++bulls;
                    } else {
                        // cow
                        ++cows;
                    }
                }
            }

        guess /= 10;
        p--;
        }
        printf("cows = %d\nbulls = %d\n", cows, bulls);
    }

    return 0;
}

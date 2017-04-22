
#include <stdio.h>
#include <string.h>

struct driving_license_t {
    char categories[11];
    int is_master;
};

int can_drive(struct driving_license_t, char[3]);

int main() {
    struct driving_license_t license = {
        .categories = "abc",
        .is_master = 0
    };
    printf("%d\n", can_drive(license, "a1"));
    printf("%d\n", can_drive(license, "c5"));
    printf("%d\n", can_drive(license, "g1"));
    return 0;
}

int can_drive(struct driving_license_t license, char to_check[3]) {
    char check_category = to_check[0];
    
    for(int i = 0;;i++){
        char c = license.categories[i];
        if(c == '\0') {
            return 0;
        }
        if(check_category == c) {
            break;
        }
    }
    
    if(strlen(to_check) == 1) {
        return 1;
    } else {
        int number = to_check[1] - '0';
        if(number <= 3) {
            return 1;
        } else {
            return license.is_master;
        }
    }
    
}
















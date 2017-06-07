#include <stdio.h>
#include <stdlib.h>

struct phonebook_entry_t {
    char name[20];
    char number[20];
};

int main() {
    int size = 10;
    int count = 0;
    char *result;
    struct phonebook_entry_t *book = calloc(size, sizeof(struct phonebook_entry_t));
    
    for(;;) {
        result = fgets((book + count)->name, 20, stdin);
        if(result == NULL) {
            break;
        }
    
        result = fgets((book + count)->number, 20, stdin);
        if(result == NULL) {
            break;
        }
    
        printf("%s - %s\n", (book + count)->name, (book + count)->number);
        count++;
        if(count == size) {
            size *= 2;
            book = realloc(book, sizeof(struct phonebook_entry_t)*size);
        }
    }

    free(book);
    return 0;
}

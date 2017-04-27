#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person_t {
	char name[20];
	int age;
	int post_code;
};

struct phonebook_entry_t {
	char phone[10];
	struct person_t *person;
};

void print_person(struct phonebook_entry_t);

int main() {

	int count = 0;
	int size = 5;
	
	struct phonebook_entry_t *book = malloc(size * sizeof(struct phonebook_entry_t));
	char name[20];
	while(scanf("%s", name) != EOF) {
		char phone[10];
		scanf("%s", phone);

		printf("%s - %s\n", name, phone);
		

		strncpy(book[count].name, name, 20);
		strncpy(book[count++].phone, phone, 10);

		//book[count].name = name;
		//book[count++].phone = phone;

		if (count == size) {
			size *= 2;
			book = realloc(book, size * sizeof(struct phonebook_entry_t));
		}
	} 

	for(int i = 0; i < count; i++) {
		printf("%s - %s\n", book[i].name, book[i].phone);
	}

	return 0;
}

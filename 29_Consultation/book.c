#include <stdio.h>

struct book_t {
		char *name[51];
		int year_of_publishing;
		int sold_copies;
};

struct bookstore_t {
		struct book_t books[10];
		int books_count;
};

int sorted_add(struct bookstore_t*, struct book_t);

int main() {
	struct book_t b1 = { .year_of_publishing = 1997 };
	struct book_t b2 = { .year_of_publishing = 2000 };
	struct book_t b3 = { .year_of_publishing = 2015 };

	struct book_t add1 = { .year_of_publishing = 2004 };
	struct book_t add2 = { .year_of_publishing = 1996 };

	struct bookstore_t bookstore;

	bookstore.books_count = 0;

	sorted_add(&bookstore, b1);
	sorted_add(&bookstore, b2);
	sorted_add(&bookstore, b3);
	sorted_add(&bookstore, add1);
	sorted_add(&bookstore, add2);


	printf("%d\n", bookstore.books_count);

	for (int i = 0; i < bookstore.books_count; i++) {
			printf("%d\n",
		bookstore.books[i].year_of_publishing);
	}



	return 0;
}

// int want_to_eat(struct food_t foods[10], int calories, int vegetarian) {
// 	int total = 0;
// 	for (int i = 0; i < 10; i++) {
// 			if (foods[i].cal < calories) {
// 				if (can_eat(foods[i], vegetarians)) {
// 					total++;
// 				}
// 			}
// 	}
//
// 	return total;
// }

int sorted_add(struct bookstore_t *store, struct book_t book) {
	if (store->books_count == 10) {
		return -1;
	}

	for (int i = 0; i < store->books_count; i++) {
		if (store->books[i].year_of_publishing >
		book.year_of_publishing) {
			for (int j = store->books_count-1; j >= i; j--) {
				store->books[j+1] = store->books[j];
			}
			store->books_count++;
			store->books[i] = book;
			return i;
		}
	}

	store->books[store->books_count] = book;
	store->books_count++;
	return store->books_count - 1;
}

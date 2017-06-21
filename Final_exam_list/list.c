#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
	int value;
	struct node_t *next;
};

struct list_t {
	struct node_t *head;
};

struct list_t* list_init();
void list_destroy(struct list_t*);

void insert(struct list_t*, int);
int remove_elem(struct list_t*);
struct node_t* create(int);
int list_size(struct list_t);

int main() {

	struct list_t *l = list_init();
	
	for(int i = 0; i <= 5; i++) {
		if(i != 4) {
			insert(l, i);
		}
	}
	printf("size: %d\n", list_size(*l));
	
	while(list_size(*l) != 0) {
		printf("%d ", remove_elem(l));
	}
	printf("\n"); // 1 2 3 4 5
	
	list_destroy(l);
	
	return 0;
}


struct list_t* list_init() {
	struct list_t *l = malloc(sizeof(struct list_t));
	l->head = NULL;
	return l;
}

void list_destroy(struct list_t* list) {
	while(list_size(*list) != 0) {
		remove_elem(list);
	}
	free(list);
}


int list_size(struct list_t l) {
	int count = 0;
	struct node_t *elem = l.head;
	for(;elem != NULL; count++, elem = elem->next) {}

	return count;
}

struct node_t* create(int value) {
	struct node_t *elem = malloc(sizeof(struct node_t));

	elem->value = value;
	elem->next = NULL;

	return elem;
}

int remove_elem(struct list_t *list) {
	struct node_t *removed = list->head;
	if(removed == NULL) {
		return -1;
	}
	int element = removed->value;

	list->head = removed->next;

	free(removed);
	return element;
}

void insert(struct list_t *list, int elem) {
	struct node_t *new_elem = create(elem);

	new_elem->next = list->head;
	list->head = new_elem;
}

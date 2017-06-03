#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_t {
	struct list_t *list;
	int size;
	int capacity;
};

struct node_t {
	int value;
	struct node_t *next;
};

struct list_t {
	struct node_t *head;
};

void push(struct stack_t*, int);
int top(struct stack_t);
void pop(struct stack_t*);
int size(struct stack_t);
struct stack_t stack_init();

void insert(struct list_t*, int);
void insert_after(struct list_t*, int);
void remove_before(struct list_t*);
void remove_after(struct list_t*);
struct node_t* create(int);
int list_size(struct list_t);

int are_ballanced(char *str);

int main() {

	struct list_t l;
	struct node_t *n = create(5);
	l.head = n;

	printf("%d\n", l.head->value);

	insert_after(&l, 10);
	remove_after(&l);

	printf("%d\n", l.head->value);
	//printf("%d\n", l.head->next->value);

	return 0;
}

int are_ballanced(char *str) {
	struct stack_t stack = stack_init();

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			push(&stack, str[i]);	
		}

		if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (size(stack) == 0) {
				return 0;
			}
			int elem = top(stack);

			if (0/* is the same as the closing bracket*/) {
				pop(stack);
			}
			else {
				return 0;
			}

		}
	}
	
	return size(stack) == 0;
}

void push(struct stack_t *s, int elem) {
	insert(s->list, elem);
}

int top(struct stack_t s) {
	return s.list->head->value;
}

void pop(struct stack_t *s) {
	remove_before(s->list);
}

int size(struct stack_t s) {
	return list_size(*(s.list));
}

int list_size(struct list_t l) {
	int count = 0;
	struct node_t *elem = l.head;
	for(;elem->next != NULL; count++, elem = elem->next) {}

	return count;
}

struct node_t* create(int value) {
	struct node_t *elem = malloc(sizeof(struct node_t));

	elem->value = value;
	elem->next = NULL;
	
	return elem;
}

void remove_before(struct list_t *list) {
	struct node_t *removed = list->head;

	list->head = removed->next;

	free(removed);
}

void remove_after(struct list_t* list) {
	struct node_t *last = list->head;
	
	if (last->next == NULL) {
		remove_before(list);
		return;
	}

	while(last->next->next != NULL) {
		last = last->next;
	}

	free(last->next);
	last->next = NULL;
}


void insert_after(struct list_t* list, int elem) {
	struct node_t *last = list->head;
	while(last->next != NULL) {
		last = last->next;
	}
	
	struct node_t *new_elem = create(elem);
	
	last->next = new_elem;
}

void insert(struct list_t *list, int elem) {
	struct node_t *new_elem = create(elem);

	new_elem->next = list->head;
	list->head = new_elem;
}

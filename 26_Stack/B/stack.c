#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_t {
	int size;
	int capacity;
	int *data;
};

struct stack_t stack_init(int);
void stack_destroy(struct stack_t*);
void push(struct stack_t*, int);
int is_full(struct stack_t);
int top(struct stack_t);
int is_empty(struct stack_t);
void pop(struct stack_t*);
int size(struct stack_t);
int get(struct stack_t*);
int calc(int, int, char);
float rpn_solve(char*);

int main() {
	struct stack_t s;
	s = stack_init(4);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);

	printf("%d\n", top(s)); // 5
	pop(&s);
	printf("%d\n", top(s)); // 4

	//struct stack_t s2 = stack_copy(s);

	char *str = "9 5 2 + - 4 + 1 -";

	printf("%f", rpn_solve(str)); // 5

	return 0;
}

float rpn_solve(char *rpn_exp) {
	struct stack_t s = stack_init(2);

	for (int i = 0; i < strlen(rpn_exp); i++) {
		if (rpn_exp[i] == ' ') { continue; }

		if (rpn_exp[i] >= '0' && rpn_exp[i] <= '9') {
			push(&s, rpn_exp[i] - '0');
		}
		//else if (rpn_exp[i] == '+' || '-' || '/' || '*') // NOT VALID!!
		else {
			if (size(s) < 2) { return 0.0; }

			int second = get(&s);
			int first = get(&s);

			push(&s, calc(first, second, rpn_exp[i]));
		}
	}

	int to_return = top(s);	
	stack_destroy(&s);

	return to_return; 
}

int calc(int first, int second, char operation) {
	int result = 0;
	
	switch(operation) {
		case '+': result = first + second; break;
		case '-': result = first - second; break;
		case '*': result = first * second; break;
		// Check for division by zero!!
		case '/': result = first / second; break;	
	}
	
	return result;		
}

int get(struct stack_t* stack) {
	int result = top(*stack);
	pop(stack);
	return result;
}

int size(struct stack_t stack) {
	return stack.size;
}

void pop(struct stack_t *stack) {
	if(is_empty(*stack)) { return; }
	stack->size--;
}

int is_empty(struct stack_t stack) {
	return stack.size == 0;
}

int top(struct stack_t stack) {
	if (is_empty(stack)) { return 0; }
	return stack.data[stack.size - 1];
}

int is_full(struct stack_t stack) {
	return stack.size == stack.capacity;
}

void push(struct stack_t *stack, int elem) {
	if (is_full(*stack)) {
		stack->data = realloc(stack->data, stack->capacity * 2);
		stack->capacity *= 2;
	}
	stack->data[stack->size++] = elem;
}

void stack_destroy(struct stack_t *stack) {
	stack->capacity = 0;
	stack->size = 0;
	free(stack->data);
	stack->data = NULL;
}

struct stack_t stack_init(int initial_capacity) {
	struct stack_t stack;
	stack.capacity = initial_capacity;
	stack.size = 0;
	stack.data = malloc(initial_capacity * sizeof(int));

	return stack;
}



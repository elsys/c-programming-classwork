#include <stdio.h>
#include <stdlib.h>


struct dynamic_arr_t {
	int *nums;
	int size;
};

struct dynamic_arr_t generate(int);
void destroy(struct dynamic_arr_t*);
struct dynamic_arr_t filter_even(struct dynamic_arr_t);

int main() {

	struct dynamic_arr_t arr = generate(5);

	printf("%d", arr.size);

	struct dynamic_arr_t odds = filter_even(arr);
	
	destroy(&arr);
	destroy(&odds);
	return 0;
}

struct dynamic_arr_t filter_even(struct dynamic_arr_t dyn) {
	struct dynamic_arr_t result = generate(dyn.size);
	int odd_index = 0;

	for (int i = 0; i < dyn.size; i++) {
		if (dyn.nums[i] % 2 != 0) {
			result.nums[odd_index++] = dyn.nums[i];
		}
	}
	result.size = odd_index;	
	
	return result;
}

struct dynamic_arr_t generate(int num) {
	struct dynamic_arr_t dyn;

	dyn.nums = malloc(num * sizeof(int));
	dyn.size = num;
	
	if (dyn.nums == NULL) { /* return error; */ }

	for (int i = 0; i < num; i++) {
		dyn.nums[i] = i + 1;
	}

	return dyn;
}

void destroy(struct dynamic_arr_t *dyn) {
	free(dyn->nums);
	dyn->size = 0;
}

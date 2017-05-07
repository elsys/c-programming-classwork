#include <stdio.h>


struct office_t {
	int rooms;
	float rent;
	int has_kitchen;
};

struct office_t find_office(struct office_t offices[10]);
int all_positive(int*, int);
int *longest_odd_even_chain(int*, int);

int main() {
	
	int nums[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9 };

	int *start = longest_odd_even_chain(nums, 11);

	printf("%d", *start);
	
	return 0;
}

int *longest_odd_even_chain2(int *arr, int size) {
	int curr = 0;
	int chain_curr = 0, chain_max = 0;
	
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == curr) {
			chain_curr++;
			curr = !curr;
		}
		else {
			// check if curr > max 
		}
	}
}

int *longest_odd_even_chain(int *arr, int size) {
	int chain_start = 0;
	int chain_max = 0;
	int chain_curr = 0;

	for (int i = 0; i < size; i++) {
		if (chain_curr % 2 == 0) {
			if (arr[i] % 2 == 0) {
				chain_curr++;
			}
			else {
				if (chain_curr > chain_max) {
					chain_max = chain_curr;
					chain_start = i - chain_curr;
				}
			}
		}
		else {
			if (arr[i] % 2 != 0) {
				chain_curr++;
			}
			else {
				if (chain_curr > chain_max) {
					chain_max = chain_curr;
					chain_start = i - chain_curr;
				}
			}
		}
	}

	return &arr[chain_start - 1];		
}

int all_positive(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) { return 0; }
	}
	
	return 1;
}

struct office_t find_office(struct office_t offices[10]) {
	for (int i = 0; i < 10; i++) {
		if (offices[i].rooms >= 3 && offices[i].rent < 500 
			&& offices[i].has_kitchen) {
			return offices[i];
		}
	}
}















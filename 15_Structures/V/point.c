#include <stdio.h>






struct point_t {
	int x;
	int y;
};

struct line_t {
	struct point_t start;
	struct point_t end;
};

struct rectangle_t {
	struct line_t up, down, left, right;
};

int are_points_equal(struct point_t, struct point_t);
void print_point(struct point_t);

int are_on_same_line(struct point_t, struct point_t); 

struct point_t sum(struct point_t, struct point_t);

int main() {
	struct rectangle_t rectangle;

	rectangle.up.start.y;

	struct line_t line;

	line.start.x;

	struct point_t p1, p2;
	int 	       a1, a2;
	
	struct point_t start, end;

	start.x = 5;
	start.y = 5;

	end.x = 20;
	end.y = 30;

	//scanf("%d%d", &p1.x, &p1.y);
	//scanf("%d", &a1);

	a2 = 6;

	p2.x = 4;
	p2.y = 6;


	print_point(p1);
	print_point(p2);
	print_point(start);
	print_point(end);

	are_points_equal(p1, p2);
	are_equal_nums(a1, a2);
	
//	printf("%d", are_on_same_line(p1, p2));
	print_point(sum(start, end));

	struct point_t example = {4, 6};
	print_point(example);
	struct point_t ex2 = { .y = 8, .x = 4};
	print_point(ex2);
	struct point_t ex3 = { y: 5, x: 5};
	print_point(ex3);
	
	return 0;
}

struct point_t sum(struct point_t p1, struct point_t p2) {
	struct point_t result;
	result.x = p1.x + p2.x;
	result.y = p1.y + p2.y;

	return result;	
}

int are_on_same_line(struct point_t p1, struct point_t p2) {
	return 1;
}	

void print_point(struct point_t p) {
	printf("(%d, %d)\n", p.x, p.y);
}

int are_points_equal(struct point_t left, struct point_t right) {
	if (left.x == right.x && left.y == right.y) return 1;

	return 0;
}

int are_equal_nums(int left, int right) {
	if (left == right) return 1;
	
	return 0;
}









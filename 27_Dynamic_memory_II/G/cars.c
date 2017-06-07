

#include <stdio.h>

struct engine_t {
    int hp;
};

struct car_t {
    struct engine_t *engine;
    int doors_count;
};

void print_car(struct car_t *car) {
    printf("doors: %d, hp: %d\n",
        car->doors_count,
        car->engine->hp);
}

int main() {
    struct engine_t v8 = { 250 };
    struct car_t toyota = {
        .engine = &v8,
        .doors_count = 5
    };

    print_car(&toyota);

    return 0;
}

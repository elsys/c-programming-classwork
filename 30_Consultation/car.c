#include <stdio.h>

struct car_t {
    int release_year;
    int release_price;
    int current_price;
};

float devaluated(struct car_t, int);
struct car_t choose_car(struct car_t cars[10], int curr_year);

int main() {

    struct car_t car1;
    
    car1.release_year = 2008;
    car1.release_price = 10000;
    car1.current_price = 7000;       
    
    struct car_t car2;
    
    car2.release_year = 2008;
    car2.release_price = 10000;
    car2.current_price = 8000;       
    
    struct car_t suzuki;
    
    suzuki.release_year = 2008;
    suzuki.release_price = 10000;
    suzuki.current_price = 6000;       
    printf("%f\n", devaluated(suzuki, 2017));

    struct car_t garage[3];
    garage[0] = suzuki;
    garage[1] = car1;
    garage[2] = car2;

    struct car_t choosen = choose_car(garage, 2017);

    printf("%d %d\n", choosen.release_year, choosen.current_price);

    return 0;
}

struct car_t choose_car(struct car_t cars[3], int curr_year) {
    struct car_t newest = cars[0];

    for (int i = 0; i < 3; i++) {
        if (cars[i].release_year > newest.release_year) {
            newest = cars[i];
        }
        
        if (cars[i].release_year == newest.release_year) {
            float i_deval = devaluated(cars[i], curr_year);
            float newest_deval = devaluated(newest, curr_year);
            
            if (i_deval < newest_deval) {
                 newest = cars[i];
            }
        }
    }

    return newest;
}

float devaluated(struct car_t car, int curr_year) {
    int diff_price = car.release_price - car.current_price;
    int diff_year = curr_year - car.release_year;

    if (diff_year == 0) {
        return 0;
    }
    
    float result = ((float) diff_price) / diff_year;
    return result;
}

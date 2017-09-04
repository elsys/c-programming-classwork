#include <stdio.h>

struct card_t {
    char suit;
    char card;
};

struct card_t fight(struct card_t, struct card_t);
int card_power(struct card_t);


int main() {

    struct card_t two;
    two.suit = 'S';
    two.card = '2';
    
    struct card_t five;
    five.suit = 'D';
    five.card = 'Q';

    printf("%c\n", fight(two, five).card);

    printf("%d", card_power(two));
    printf("%d", card_power(five));

    return 0;
}

int card_power(struct card_t card) {
    int power;
    switch (card.card) {
        case 'A': power = 14; break;
        case 'K': power = 13; break;
        case 'Q': power = 12; break;
        case 'J': power = 11; break;
        case 'T': power = 10; break;
        
        default: power = card.card - '0'; break;
    }

    return power;
}

struct card_t fight(struct card_t one, struct card_t two) {
    int one_power = card_power(one);
    int two_power = card_power(two);

    struct card_t to_return = one;

    //if (one_power > two_power) {
    //    return one;
    //}
    //else 
    if (two_power > one_power) {
        to_return = two;
    }
    else if (two_power == one_power) {
        //if(one.suit > two.suit) {
        //    return one;
        //}
        //else 
        if(two.suit > one.suit) {
            to_return = two;
        }
    }
    
    return to_return;
}

#ifndef JAKUBANDRYSEK_PR5_07_BACKTRACKING_DAMY_CLION_ZASOBNIK_H
#define JAKUBANDRYSEK_PR5_07_BACKTRACKING_DAMY_CLION_ZASOBNIK_H

#include <stdbool.h> // pro praci s typem bool a konstantami true a false

typedef struct _prvek Tprvek;

struct _prvek {
    char hodnota[8];
    Tprvek * dalsi;
};

typedef struct {
    Tprvek* vrchol;
    int vyska;
} Tzasobnik;


Tzasobnik* zasInitD(void);

Tprvek* prvekNovy(char hodnota[]);

bool zasPush(Tzasobnik * zasobnik, char hodnota[]);

bool zasPop(Tzasobnik * zasobnik, char data[]);

void zasVypis(Tzasobnik * zasobnik);

bool zasZrus(Tzasobnik * zasobnik);

#endif //JAKUBANDRYSEK_PR5_07_BACKTRACKING_DAMY_CLION_ZASOBNIK_H

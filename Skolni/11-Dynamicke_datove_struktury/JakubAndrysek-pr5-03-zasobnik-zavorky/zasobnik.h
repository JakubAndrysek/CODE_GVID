#ifndef ZASOBNIK_H_INCLUDED
#define ZASOBNIK_H_INCLUDED

#include <stdbool.h> // pro praci s typem bool a konstantami true a false

typedef struct _prvek Tprvek;

struct _prvek {
	char hodnota;
	Tprvek * dalsi;
};

typedef struct {
	Tprvek* vrchol;
	int vyska;
} Tzasobnik;


Tzasobnik* zasInitD(void);

Tprvek* prvekNovy(char hodnota);

bool zasPush(Tzasobnik * zasobnik, char hodnota);

bool zasPop(Tzasobnik * zasobnik, char * data);

void zasVypis(Tzasobnik * zasobnik);

bool zasZrus(Tzasobnik * zasobnik);



#endif // ZASOBNIK_H_INCLUDED

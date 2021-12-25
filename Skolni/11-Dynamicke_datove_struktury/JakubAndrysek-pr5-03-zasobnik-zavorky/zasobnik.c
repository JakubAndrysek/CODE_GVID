#include <stdio.h>
#include <stdlib.h>
#include "zasobnik.h"


Tzasobnik* zasInitD(void){
	Tzasobnik* z = malloc(sizeof(Tzasobnik));
	if(z == NULL) {
		return NULL;
	}
	z->vrchol = NULL;
	z->vyska = 0;
	return z;
}

Tprvek* prvekNovy(char hodnota) {
	Tprvek* novy=malloc(sizeof(Tprvek));
	if (novy != NULL) {
		novy->hodnota = hodnota;
		novy->dalsi = NULL;
	}
	return novy;
}

bool zasPush(Tzasobnik * zasobnik, char hodnota) {
	Tprvek* novy = prvekNovy(hodnota);
	if(novy == NULL) {
		return false;
	}
	if(zasobnik->vrchol == NULL) {
		zasobnik->vrchol = novy;
	} else {
		novy->dalsi = zasobnik->vrchol;
		zasobnik->vrchol = novy;
	}
	return true;
}

bool zasPop(Tzasobnik * zasobnik, char * data) {
	if(zasobnik->vrchol == NULL) {
		return false;
	}
	*data = zasobnik->vrchol->hodnota;
	Tprvek * smazanyVrch = zasobnik->vrchol;
	zasobnik->vrchol = zasobnik->vrchol->dalsi;
	free(smazanyVrch);
	return true;
}

void zasVypis(Tzasobnik * zasobnik) {
	Tprvek * prvek = zasobnik->vrchol;

	while (prvek != NULL) {
		printf("%c\n", prvek->hodnota);
		prvek = prvek->dalsi;
	}
}

bool zasZrus(Tzasobnik * zasobnik) {
	if(zasobnik == NULL) {
		return false;
	}
	char pom;
	while(zasPop(zasobnik, &pom)) {;}
	free(zasobnik);
	return true;
}

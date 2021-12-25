#include "zasobnik.h"
#include <stdio.h>
#include <stdlib.h>

Tzasobnik* zasInitD(void){
    Tzasobnik* z = malloc(sizeof(Tzasobnik));
    if(z == NULL) {
        return NULL;
    }
    z->vrchol = NULL;
    z->vyska = 0;
    return z;
}

Tprvek* prvekNovy(char hodnota[]) {
    Tprvek* novy=malloc(sizeof(Tprvek));
    if (novy != NULL) {
        for(int i=0; i<8; i++) {
            novy->hodnota[i] = hodnota[i];
        }
        novy->dalsi = NULL;
    }
    return novy;
}

bool zasPush(Tzasobnik * zasobnik, char hodnota[]) {
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

bool zasPop(Tzasobnik * zasobnik, char data[]) {
    if(zasobnik->vrchol == NULL) {
        return false;
    }
    for(int i=0; i<8; i++) {
        data[i] = zasobnik->vrchol->hodnota[i];
    }

    Tprvek * smazanyVrch = zasobnik->vrchol;
    zasobnik->vrchol = zasobnik->vrchol->dalsi;
    free(smazanyVrch);
    return true;
}

void zasVypis(Tzasobnik * zasobnik) {
    Tprvek * prvek = zasobnik->vrchol;
    int poc = 1;

    while (prvek != NULL) {
        printf("%2d -> [%d", poc, prvek->hodnota[0]);
        for(int i=1; i<8; i++) {
            printf(",%d", prvek->hodnota[i]);
        }
        printf("]\n");

        prvek = prvek->dalsi;
        poc++;
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


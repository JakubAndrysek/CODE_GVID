/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // pro praci s textovymi retezci
#include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem
#include "zasobnik.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct {
    char ypozice[8];
    bool jevradku[8];
    bool jesikmozleva[15];
    bool jesikmozprava[15];
} TSach;

bool jeOhrozena(TSach *plocha, int x, int y) {
    bool ohrozena = (plocha->jevradku[y] || plocha->jesikmozleva[x+y] || plocha->jesikmozprava[x-y+7]);
    return ohrozena;
}

void polozDamu(TSach *plocha, int x, int y) {
    plocha->ypozice[x] = y+1;
    plocha->jevradku[y] = true;
    plocha->jesikmozleva[x+y] = true;
    plocha->jesikmozprava[x-y+7] = true;
}

void odeberDamu(TSach *plocha, int x, int y) {
    plocha->ypozice[x] = 0;
    plocha->jevradku[y] = false;
    plocha->jesikmozleva[x+y] = false;
    plocha->jesikmozprava[x-y+7] = false;
}

void zapamatuj(TSach *plocha, Tzasobnik* reseni) {
    zasPush(reseni, plocha->ypozice);
}

void zkusSloupec(TSach *plocha, int x, Tzasobnik * reseni) {
    for(int y = 0; y<8; y++) {
        if(!jeOhrozena(plocha, x, y)) {
            polozDamu(plocha, x, y);

            if (x == 7) {
                zapamatuj(plocha, reseni);
            } else {
                zkusSloupec(plocha, x + 1, reseni);
            }

            odeberDamu(plocha, x, y);
        }
    }
}

void vypisJednoReseni(char reseni[], int poc) {
    printf(ANSI_COLOR_BLUE "Reseni cislo: %d\n" ANSI_COLOR_RESET, poc);
    for(int y = 8; y  > 0; y--) {
        for(int x = 0; x < 8; x++) {
            if(reseni[x] == y) {
                printf(ANSI_COLOR_RED "x  " ANSI_COLOR_RESET);
            } else {
                printf(ANSI_COLOR_GREEN "o  " ANSI_COLOR_RESET);
            }
        }
        printf("\n");
    }

    for(int i = 0; i < 8; i++) {
        printf(ANSI_COLOR_BLUE "%d  " ANSI_COLOR_RESET, reseni[i]);
    }
    printf("\n\n");
}

void resDamy() {

    Tzasobnik* reseni = zasInitD();

    TSach plocha = {
            .ypozice = {0},
            .jevradku = {false},
            .jesikmozleva = {false},
            .jesikmozprava = {false},
    };

    zkusSloupec(&plocha, 0, reseni);

    int poc = 1;
    char jednoReseni[8];

    while (zasPop(reseni, jednoReseni)) {
        vypisJednoReseni(jednoReseni, poc);
        poc++;
    }
    zasVypis(reseni);
}

int main(void)
{
    resDamy();
    return 0;
}

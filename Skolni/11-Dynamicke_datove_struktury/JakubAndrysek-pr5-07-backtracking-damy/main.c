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

typedef struct {
	char ypozice[8];
	bool jevradku[8];
	bool jesikmozleva[15];
	bool jesikmozprava[15];
} TSach;

typedef struct {
/* lin. seznam */
} TReseni;

//TSach* initPlocha() {
//
//
//  return plocha;
//}

bool jeOhrozena(TSach *plocha, int x, int y) {
  return (plocha->jevradku[x] || plocha->jesikmozleva[x+y] || plocha->jesikmozprava[x-y+7]);
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

void zapamatuj(TSach *plocha, int reseni[]) {
  reseni = plocha->ypozice;
}

void zkusSloupec(TSach *plocha, int x, int reseni[]) {
  for(int y = 0; y<8; y++) {
    if(!jeOhrozena(plocha, x, y)) {
      polozDamu(plocha, x, y);
    }

    if(x == 7) {
      zapamatuj(plocha, reseni);
//      for(int y = 0; y<8; y++){
//        printf("|");
//        for(int x = 0; x<8; x++) {
//
//        }
//      }
    } else {
      zkusSloupec(plocha, x + 1, reseni);
    }

    odeberDamu(plocha, x, y);
  }
}

void resDamy() {
//  TSach* plocha = initPlocha();
  TSach plocha = {
		.ypozice = {0},
		.jevradku = {false},
		.jesikmozleva = {false},
		.jesikmozprava = {false},
	};

  int reseni[8] = {0};

  zkusSloupec(&plocha, 0, &reseni);

  printf("Jej\n");


}

int main(void)
{
  resDamy();

  return 0;
}

/*
 * Projekt: kvadraticka rovnice
 * Autor: Jakub Andrysek
 * Datum: 15. 9. 2021
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
#include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
#include <math.h>    // funkce z matematicke knihovny sqrt
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

typedef struct {
  float a, b, c;
} Trovnice;

typedef struct {
  float x1, x2;
} Treseni;

bool nactiKoeficient(char *dotaz, float *vysledek) {
  int e;
  do {
    printf("%s", dotaz);
    e = scanf("%f", vysledek);
    if (e == 0) {
      scanf("%*s");
      printf("Chybne zadano\n");
    }

    if( e == EOF) {
      return false;
    }
  } while(e != 1);
  return true;
}

Trovnice nactiKoeficienty1() {
  Trovnice rovnice;

  printf("Zadej postupne koeficienty rovnice: \n");

  nactiKoeficient("Koeficient A: ", &rovnice.a);
  nactiKoeficient("Koeficient B: ", &rovnice.b);
  nactiKoeficient("Koeficient C: ", &rovnice.c);

  return rovnice;
}

void nactiKoeficienty2(Trovnice *rovnice) {

  printf("Zadej postupne koeficienty rovnice: \n");

  nactiKoeficient("Koeficient A: ", &rovnice->a);
  nactiKoeficient("Koeficient B: ", &rovnice->b);
  nactiKoeficient("Koeficient C: ", &rovnice->c);
}

float rovnice(Trovnice rov, float d, int kladZapor) {
  float r = (-rov.b+(kladZapor*sqrt(d)))/(2*rov.a);
  return r;
}

int kvRov(Trovnice rov, Treseni *reseni){
  float d;

  d = pow(rov.b, 2)-4*rov.a*rov.c;

  if(d < 0) {
    return 0;
  }

  if(d == 0) {
    reseni->x1 = (rov, d, 1);
    return 1;
  }

  reseni->x1 = rovnice(rov, d, 1);
  reseni->x2 = rovnice(rov, d, -1);
  return 2;
}

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{

  Trovnice rovnice;

//  rovnice = nactiKoeficienty1();
// 2 varianty
  nactiKoeficienty2(&rovnice);

  printf("Tvoje rovnice: %g*x^2 + %g*x + %g = 0\n", rovnice.a, rovnice.b, rovnice.c);

  Treseni reseni;
  int pocetKorenu;

  pocetKorenu = kvRov(rovnice, &reseni);

  if(pocetKorenu == 0) {
    printf("Rovnice nema zadne reseni\n");
  }
  else if(pocetKorenu == 1) {
    printf("Rovnice ma jedno reseni: %g\n", reseni.x1);
  }
  else {
    printf("Rovnice ma dve reseni: %g a %g\n", reseni.x1, reseni.x2);
  }

  return 0;
}

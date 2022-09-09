/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

#define MAXN 100


typedef struct {
float prvek[MAXN][MAXN];
  int radku, sloupcu;
} Tmatice;




void ctiM(FILE *in, Tmatice *m) {
  if(fscanf(in, "%d %d\n", &m->radku, &m->sloupcu) == 2){
    printf("E: nenacteny rozmery matice\n");
    return;
  }

  for(int r = 0; r<m->radku, r++) {
    for(int s = 0; s< m->sloupcu, s++) {
      if(fscanf(in, "%f ", m->prvek[r][s])==1) {
        printf("E: cteni matice r:%d s:%d\n", r, s);
      }
    }
  }
}

void tiskM(FILE *out, Tmatice *m) {

}


void testCteni()


//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{

  Tmatice mat = {.radku = 10, .sloupcu = 3};
  mat.prvek[0][0] = 123;

  ctiM(stdin, &mar);

  return 0;
}

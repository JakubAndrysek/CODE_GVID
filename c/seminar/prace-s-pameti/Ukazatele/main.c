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

typedef struct {
  int** data;
  int radku;
  int sloupcu;
} TPole2d;


TPole2d* vyrob2Dpole(int radku, int sloupcu) {
  TPole2d *pole2d = malloc(sizeof(TPole2d));

  pole2d->data = malloc(radku*sizeof(int*));
  if(pole2d->data == NULL) {
    printf("E: data nevytvoreny\n");
    exit(0);
  }

  for(int i = 0; i<radku; i++) {
    pole2d->data[i] = malloc(sloupcu * sizeof(int));
    if(pole2d->data[i] == NULL) {
      printf("E: data %d nevytvorena", i);
      pole2d->radku = i;
      pole2d->sloupcu = sloupcu;
    }
  }

  pole2d->radku = radku;
  pole2d->sloupcu = sloupcu;

  return pole2d;
}

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
  TPole2d* pole2d = vyrob2Dpole(5, 5);

  pole2d->data[0][0] = 55;

  printf("Data: %d", pole2d->data[0][0]);

  return 0;
}

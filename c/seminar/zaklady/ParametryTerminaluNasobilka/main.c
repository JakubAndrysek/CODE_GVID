/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem


int nactiCislo(char str[]) {
  char *ptr;
  long ret = strtol(str, &ptr, 10);
  if(*ptr != '\0') {
    printf("Nepodaril se prevest parametr '%s' na cislo\n");
    return -1;
  }
  return ret;
}

void vypisParametr(char arg[], int index) {
  printf("[%d] -> '%s' \n", index, arg);
}

void vypisParametry(int argc, char *argv[]) {
  printf("Parametry programu\n");
  for(int index = 0; index<argc; index++) {
      char* arg = argv[index];
      vypisParametr(arg, index);
  }
  printf("\n");
}


void zobrazNapovedu() {
  printf("Napoveda\n");
  printf("Tento program vytiskne zadany pocet radku nasobilky zadaneho zakladu.\n\
Priklad: program.exe 3 2\n\
2x1 = 2\n\
2x2 = 4\n\
2x3 = 6\n\n\
Pri pouziti parametru -h se vypise napoveda k pouziti programu.\n\n");
}

void zobrazNasobilku(int pocet, int zaklad) {
  for(int i = 1; i <=pocet; i++) {
    printf("%dx%d = %d\n", zaklad, i, zaklad*i);
  }
}

void nasobilka(char pocetS[], char zakladS[]) {
  int pocet = nactiCislo(pocetS);
  int zaklad = nactiCislo(zakladS);

  if(pocet == -1 || zaklad == -1){
    return EXIT_FAILURE;
  }

  zobrazNasobilku(pocet, zaklad);
}

void projdiParametry(int argc, char *argv[]) {
  for(int index = 1; index<argc; index++) {
      char* arg = argv[index];

      if(strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
        zobrazNapovedu();
        return;
      }
  }

  if(argc >= 3) {
    nasobilka(argv[1], argv[2]);
  }

}

int main(int argc, char *argv[])  // pro parametry prikazoveho radku
{
  vypisParametry(argc, argv);
  projdiParametry(argc, argv);
  return 0;
}

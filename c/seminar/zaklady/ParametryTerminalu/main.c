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


void zobrazNapovedu() {
  printf("Napoveda");
}

void vypisParametry(char argv[]){
  printf("%s\n", argv);
}

void projdiParametry(int argc, char *argv[]) {
  for(int index = 0; index<argc; index++) {
      char* arg = argv[index];
      vypisParametry(arg);
      printf("%s\n", arg);
      if(strcmp(arg, "help") == 0) {
        zobrazNapovedu();
      }
  }
}



int main(int argc, char *argv[])  // pro parametry prikazoveho radku
{
  projdiParametry(argc, argv);
  getchar();

  return 0;
}

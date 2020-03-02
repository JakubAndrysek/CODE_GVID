/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionální typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celoèíselné typy INT_MAX, INT_MIN, ...


//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##
  // Pomucka pro ladeni. Pokud to nepouzijete, klidne to smazte.

  // Po odkomentovani se nebudou tisknout ladici zpravy.
  // #define NDEBUG

  // Prikaz dprintf pro tisk ladicich zprav. Funguje stejne jako printf,
  // ale jde jej globalne vypnout odkomentovanim definice symbolu NDEBUG.
  // Vhodny pro povidani s uzivatelem v prubehu ladeni.
  #ifdef NDEBUG
    #define dprintf(...)
  #else
    #define dprintf(...) printf(__VA_ARGS__)
  #endif //NDEBUG
//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##


// zkratka
typedef unsigned int uint;

int delkaRetezce(char retez[])
{
  int delkaTextu;
  for(delkaTextu = 0; retez[delkaTextu] != '\0'; delkaTextu++)
  {
    ;
  }
  return delkaTextu;
}

void zvojeni(char retez[])
{
  int delkaTextu;

  scanf("%19s", retez);
  for(delkaTextu = 0; retez[delkaTextu] != '\0'; delkaTextu++)
  {
    ;
  }

  for(int x = 0; x < delkaTextu; x++)
  {
    printf("%c%c", retez[x], retez[x]);
  }
}

void ukol1()
{
  char retez[20];
  zvojeni(retez);
}


int main()
{
  ukol1();
  return 0;
}

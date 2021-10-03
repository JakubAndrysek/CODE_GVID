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
// #include <limits.h>  // konstanty pro celočíselné typy INT_MAX, INT_MIN, ...


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


//
int pole[100];

void test(void)
{
  printf("Makej!\n");
}


void nactiPole(int mojePole[], int pocet)
{
  for(int i = 0; i<pocet; i++)
  {
    int znak;
    scanf("%d", &mojePole[i]);
  }
}


void ukol1()
{
  int poc = 5;
  int pole[poc];

  nactiPole(pole, poc);
}


void vypisPole(int mojePole[], int pocet)
{
  for(int i = 0; i<pocet; i++)
  {
    printf("%d, ", mojePole[i]);
  }
  printf("\n");
}

void ukol2()
{
  int poc = 8;
  int pole[] = {1,5,8,7,5,6,12,255};

  vypisPole(pole, poc);
}

void ukol2plus()
{
  int poc = 5;
  int pole[poc];

  nactiPole(pole, poc);
  vypisPole(pole, poc);
}


void sectiPole(int mojePole[], int pocet)
{
  int soucet = 0;
  for(int i = 0; i<pocet; i++)
  {
    soucet += mojePole[i];
  }
  printf("Soucet je: %d", soucet);
}


void ukol3()
{
  int poc = 5;
  int pole[poc];

  nactiPole(pole, poc);
  vypisPole(pole, poc);
  sectiPole(pole, poc);
}


int main(int argc, char *argv[])
{

  //ukol1();
  //ukol2();
  //ukol2plus();
  ukol3();
  return 0;
}

/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
 #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
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

void ukol1()
{
  int a, poc = 0;
  while(((a = getchar()) != '\n'))
  {
    putchar(a);
    poc++;
  }
  printf("\nNacetlo se %d znaku\n", poc);
}

void ukol1B()
{
  int a, poc = 0;
  while(((a = getchar()) != '\n'))
  {
    a = toupper(a); //Prevod malych pismen na velka
    putchar(a);
    poc++;
  }
  printf("\nNacetlo se %d znaku\n", poc);
}


void ukol2A()
{
  int a, posun = 2;
  while(((a = getchar()) != '\n'))
  {
    putchar(a+posun);
  }
}

void ukol2B()
{
  int a, posun = 0;
  printf("Zadej posun:");
  scanf("%d", &posun);
  printf("%d", posun);
  while(((a = getchar()) != '\n'))
  {
    putchar(a);
  }
}



int main()
{
  ukol1();
  //ukol1B();
  //ukol2A();
  //ukol2B();
  return 0;
}

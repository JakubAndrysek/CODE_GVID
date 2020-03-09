/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // pro praci s textovymi retezci
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

void zdvojeni(char retez[])
{
  scanf("%19s", retez);

  for(int x = 0; x < delkaRetezce(retez); x++)
  {
    printf("%c%c", retez[x], retez[x]);
  }
}

void ukol1()
{
  char retez[20];
  zdvojeni(retez);
}

void otocVypis(char retez[])
{
  for(int i = delkaRetezce(retez)-1; i >= 0; i--)
  {
    printf("%c", retez[i]);
  }
}

void otocDoRetezce(char vstup[])
{
  int delka = strlen(vstup);

  for(int i = 0; i < delka/2; ++i)
  {
    char pom = vstup[i];
    vstup[i] = vstup[delka-i-1];
    vstup[delka-i-1] = pom;
  }

}


void ukol2()
{
  char retez[21];
  char retezVystup[21];

  scanf("%20s", retez);
  printf("%s", retez);
  printf("\nOtoc: ");
  otocVypis(retez);

  printf("\nOtocRetez: ");
  otocDoRetezce(retez);
  puts(retez);
}


void naplnZnakem(char retez[], int velikost, char znak)
{
  for(int i = 0; i < velikost; i++)
  {
    retez[i] = znak;
  }
  retez[velikost] = '\0';
}


void ukol3()
{
  char retez[101] = ""; //prazdny retezec
  char znak = 'k';
  naplnZnakem(retez, 8, znak);
  printf("V poli je %s", retez);

}


int main()
{
  //ukol1();
  //ukol2();
  ukol3();
  return 0;
}

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

int pocetCifer(int cislo)
{
  if(cislo == 0)
  {
    return 1;
  }

  int cifra = 0;

  while(cislo != 0)
  {
    cifra++;
    cislo /= 10;
  }
  return cifra;
}

void cisloNaRet(char ret[], int cislo, int cifry)
{
  int poc = cifry;
  while(cislo != 0)
  {
    ret[poc-1] = '0' + cislo%10;
    cislo/=10;
    poc--;
  }
  ret[cifry] = '\0';
}

int main(void)
{
  printf("Zadej kladne cele cislo: ");

  int cisloInt = 0;

  scanf("%d", &cisloInt);

  int cifry = pocetCifer(cisloInt);

  char cisloChar[cifry+1];

  cisloNaRet(cisloChar, cisloInt, cifry);

  printf("Retezec: ");

  puts(cisloChar);

}

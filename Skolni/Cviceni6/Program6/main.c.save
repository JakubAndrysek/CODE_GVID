/*
 * Projekt:   Program6
 * Autor:     Jakub Andrysek
 * Datum:     2019-12-
 */

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
#include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionální typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celoèíselné typy INT_MAX, INT_MIN, ...

#define PI 3.14159

// zkratka
typedef unsigned int uint;


//Bonus
int pocetCislic(int vstup)
{
  vstup = abs(vstup); //prevede zaporne cislo na kladne
  int pocitadlo = 0;
  if(vstup == 0)
    return 1;
  else
  {
      while(vstup != 0)
    {
      pocitadlo++;
      vstup/=10;
    }
    return pocitadlo;
    return 1;
  }

}

void pocetCislicUziti()
{
  int pocet = pocetCislic(-54321);
  printf("Toto cislo ma %d cislic", pocet);
  return 0;
}



//Ukol1
float obvodObdelniku(float a, float b)
{
  return (2*a+2*b);
}

void ukol1()
{
  printf("Obvod obdelniku je %g\n", obvodObdelniku(5,6));

  float x, y;
  printf("\nNove zadani\nZadej 2 strany\n");
  scanf("%f%f", &x, &y);
  printf("Obvod obdelniku je %g", obvodObdelniku(x,y));
}

//Ukol2
float obsahKruznice(int polomer)
{
  return PI*polomer*polomer;
}

void ukol2()
{
  printf("Obsah kruznice je %g\n", obsahKruznice(5));

  float x;
  printf("\nNove zadani\nZadej polomer\n");
  scanf("%f", &x);
  printf("Obsah kruznice je %g", obsahKruznice(x));
}

long faktorial(long x)
{
  // koncova podminka, primitivni pripad
  if (x == 0)
  {
    return 1;
  }
  // rekurzivni pripad - musi resit jednodussi ulohu
  // zjednoduseni musi mirit k primitivnimu pripadu
  return x * faktorial(x-1);
}

ukol3()
{
  printf("Faktorial 5 je: %l\n", faktorial(3));

  float x;
  printf("\nNove zadani\nCislo pro faktorial\n");
  scanf("%f", &x);
  printf("Faktorial %l je: %l\n", x, faktorial(x));
}


int main()
{

  //pocetCislicUziti();
  //ukol1();
  //ukol2();
  ukol3();



}

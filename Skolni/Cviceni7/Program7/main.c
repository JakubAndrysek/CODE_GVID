
/*
 * Projekt:   Program7
 * Autor:     Jakub Andrysek
 * Datum:     2020-1-4
 */

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
#include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionální typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celočíselné typy INT_MAX, INT_MIN, ...


// zkratka
typedef unsigned int uint;


void test(void)
{
  printf("Makej!\n");
}

float zlomek(float n)
{

  if(n==0)
  {
    return 0;
  }
  else
  {
    return (1.0/n);
  }

  //  nebo
  //  return (n == 0.0)? 0.0 : 1.0/n;
}

void ukol1()
{
  printf("Vysledek je %g\n", zlomek(5));

  printf("Zadavej cisla, ukonci pomoci CTRL+Z\n");
  float a;

  while(scanf("%f", &a) == 1)
  {
    printf("1/%g je %g\n", a, zlomek(a));
  }
}

int pocetCifer(int n)
{
  int pocet = 0;
  if(n == 0)
  {
    return 0;
  }
  else
  {
    while(n != 0)
    {
      pocet++;
      n/=10;
    }
  }
  return pocet;
}

void ukol2()
{
  printf("Vysledek je %d\n", pocetCifer(546));

  printf("Zadavej cisla, ukonci pomoci CTRL+Z\n");
  int a;

  while(scanf("%d", &a) == 1)
  {
    printf("Cislo %d ma %d cif...\n\n", a, pocetCifer(a));
  }
}

int prvniCifra(int n)
{
  while(n > 9)
  {
    n/=10;
  }
  return n;
}

void ukol3()
{
  printf("Vysledek je %d\n", prvniCifra(5));

  printf("Zadavej cisla, ukonci pomoci CTRL+Z\n");
  int a;

  while(scanf("%d", &a) == 1)
  {
    printf("Prvni cifra z cisla %d je %d\n", a, prvniCifra(a));
  }
}

void od1DoN(int a)
{
  printf("%d", 1);
  for(int i = 2; i<=a; i++)
  {
    printf(", %d", i);
  }
  printf("\n");
}


void ukol4()
{

  od1DoN(8);

  printf("Zadavej cisla, ukonci pomoci CTRL+Z\n");
  int a;

  while(scanf("%d", &a) == 1)
  {
    od1DoN(a);
    printf("\n");
  }
}

bool jePrvocislo(int n)
{

  if(n < 1) return false;
  for (int i = 2; i <= n/2; ++i )
  {
    if(n%i == 0)
    {
      return false;
    }
  }
  return true;

}

void ukol5()
{
  printf("Je cislo 8 prvocislo? -> %d\n", jePrvocislo(8));

  printf("Zadavej cisla, ukonci pomoci CTRL+Z\n");
  int a;

  while(scanf("%d", &a) == 1)
  {
    printf("Je cislo %d prvocislo? -> %d\n",a, jePrvocislo(a));
  }

}


bool jeRostouci()
{
  int pocet;
  scanf("%d", &pocet);
  for(int i = 0; i < pocet, i++)
  {

  }
}

int main()
{
  //ukol1();
  //ukol2();
  //ukol3();
  //ukol4();
  ukol5();
  return 0;
}


/*
 * Projekt: Program5
 * Autor:   Jakub Andrysek
 * Datum:   2019-12-9
 */

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
 #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racion�ln� typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celo��seln� typy INT_MAX, INT_MIN, ...


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
  while(((a = getchar()) != '\n' && a != EOF))
  {
    putchar(a+posun);
  }
}


void cesar(int posun)
{
  int a;
  while(((a = getchar()) != '\n' && a != EOF))
  {
    putchar(a+posun);
  }
}

void ukol2B()
{
  int a, posun;
  printf("Zadej posun:");
  scanf("%d ", &posun);

  cesar(posun);
}

void ukol3()
{
  int cislo;
  scanf("%d", &cislo);
  while(cislo != 0)
  {
    putchar(('0'+(cislo%10)));
    cislo/=10;
  }
}


void ukol4()
{
  int cislo, vystup = 0;
  printf("Zadej cislo, ktere mam prevratit:");
  scanf("%d", &cislo);
  while(cislo != 0)
  {
    vystup = vystup*10+(cislo%10);
    cislo/=10;
  }
  printf("\nPrevracene cislo:%d\n",vystup);
}

void ukol5A()
{
  int pocet, vstup, pocitadlo = 0;
  printf("Zadej pocet nacitanych cisel\n", pocet);
  scanf("%d", &pocet);
  printf("Zadej %d cislel\n", pocet);
  for(int i = 0; i < pocet; i++)
  {
  	scanf("%d", &vstup);
  	if(vstup == 7)
  	{
  		pocitadlo++;
  	}
  }
  printf("Pocet vyskytu cisla 7 je:%d", pocitadlo);
}


int main()
{
  //ukol1();
  //ukol1B();
  //ukol2A();
  //ukol2B();
  //ukol3();
  //ukol4();
  //ukol5A();
  return 0;
}

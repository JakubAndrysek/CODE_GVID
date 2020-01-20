/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
#include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racion�ln� typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celo��seln� typy INT_MAX, INT_MIN, ...


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


int VratPocetVyskytuCifry(int vstup, int hledej)
{
  int pocet = 0;

  if(!(vstup > 0 && hledej >=0 && hledej <=9))
  {
    printf("Nezadal jsi cele kladne cislo...\n");
    return -1;  //ERROR
  }

  while(vstup!=0)
  {
    if(vstup%10 == hledej)
    {
      pocet++;
    }
    vstup/=10;
  }
  return pocet;
}


void ukol1()
{
  printf("Vrat pocet vyskutu cifry 5 v cisle 245865 je %d\n\n", VratPocetVyskytuCifry(245865, 5));

  int a, b;

  printf("Zadej cislo ve kterem mam hledat, pote zadej co mam hledat, cyklus ukonci pomoci CTRL+Z\n");

  while(scanf("%d %d", &a, &b) != 1)
  {

    printf("Pocet vyskutu cifry %d v cisle %d je %d\n\n", b, a, VratPocetVyskytuCifry(a, b));
    printf("Zadej cislo ve kterem mam hledat, pote zadej co mam hledat, cyklus ukonci pomoci CTRL+Z\n");
  }
}


int pocetDelitelu(int vstup)
{
  if (vstup < 0)
  {
    printf("Nezadal jsi cele kladne cislo...\n");
    return -1;
  }

  int pocet = 0;

  printf("Delitele cisla %d jsou: ", vstup);

  for(int i = 1; i<=vstup; i++)
  {

    if(vstup%i == 0)
    {
      pocet++;
      printf("%d, ", i);
    }
  }

  return pocet;
}

int ukol2()
{
  printf("-> cislo ma %d delitelu\n\n", pocetDelitelu(12));



  int a;

  printf("Zadej cele kladne cislo, cyklus ukonci pomoci CTRL+Z\n");

  while(scanf("%d", &a) == 1)
  {

    printf("-> cislo ma %d delitelu\n", pocetDelitelu(a));
    printf("Zadej cislo, cyklus ukonci pomoci CTRL+Z\n\n");
  }
}




//Program z minule hodiny
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

//Delime cislo postupne nejmensim moznym prvocislem
int pocetPrvociselRada(int vstup)
{
  int prvocislo = 2;


  return vstup;
}

int ukol3()
{
  printf(" a ma %d delitelu\n", pocetPrvociselRada(15));
}

int kalkulacka(int a, int b, char operace)
{

  switch(operace)
  {
  case '+':
    return a+b;
    break;

  case '-':
    return a-b;
    break;

  case '*':
    return a*b;
    break;

  case '/':
    return a/b;
    break;

  default:
    printf("ERROR\n");
  }

}


void ukol4()
{
  int a, b;
  char operace;

  printf("Kalkulacka -> Zadej cislo, operator, cislo    priklad->(5+15)\n");
  while(scanf("%d %c %d", &a, &operace, &b)==3)  //musi tam byt mezery -> "%d %c %d"
  {
    int c = kalkulacka(a, b, operace);
    printf("%d %c %d = %d\n");
  }
}




int main()
{
  //ukol1();
  //ukol2();
  //ukol3();
  ukol4();
  return 0;
}

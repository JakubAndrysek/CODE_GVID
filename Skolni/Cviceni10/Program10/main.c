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
#include <math.h>    // funkce z matematicke knihovny
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


int spoleciDelitele(int a, int b)
{
  int pocet = 0;

  printf("Vsichni delitele cisel %d a %d ->", a, b);

  if(a>b)
  {
    int c = a;
    a = b;
    b = c;
  }

  printf("{ 1 ");
  for(int i = 2; i <= b; i++)
  {
    if((a%i==0)&&(b%i==0))
    {
      printf(", %d ",i);
      pocet++;
    }
  }
  printf("}");
  return pocet;
}



void ukol1()
{
  printf("ma %d spolecnych delitelu", spoleciDelitele(20, 10));

  printf("\nZadej cele kladne cislo, cyklus ukonci pomoci CTRL+Z\n");

  int a, b;
  while(scanf("%d %d", &a, &b) == 2)
  {

    printf("ma %d spolecnych delitelu", spoleciDelitele(a, b));
    printf("Zadej cislo, cyklus ukonci pomoci CTRL+Z\n\n");
  }

}

float prumer(int a, int b, int c, int d)
{
  if((a*b*c + a*b*d + b*c*d)==0)
  {
    return 0;
  }

  return (a+b+c+d)/4.0;

}

void vypisPrumer(int a, int b, int c, int d)
{
  float fprumer = prumer(a, b, c, d);



  printf("Prumer tvych zamek je %g\n", fprumer);
  int rPrumer = round(fprumer);
  switch(rPrumer)
  {
  case 0:
    printf("Nehodnocen");
    break;
  case 1:
    printf("Vyborny");
    break;
  case 2:
    printf("Dobry");
    break;
  case 3:
    printf("Chvalitebny");
    break;
  case 4:
    printf("Dostatecny");
    break;
  case 5:
    printf("Nedostatecny");
    break;
  }
  printf("\n");

}

ukol2()
{
  vypisPrumer(1,1,2,0);

  printf("\nZadej 4 znamky z IVT, cyklus ukonci pomoci CTRL+Z\n");

  int a, b, c, d;
  while(scanf("%d %d %d %d", &a, &b, &c, &d) == 4)
  {
    vypisPrumer(a, b, c, d);
  }
}

int fibonaciRekurze(int x)
{
  if(x==0){return 0;}
  if(x==1){return 1;}
  return fibonaciRekurze(x-1)+fibonaciRekurze(x-2);
}

int fibonaci(int n)
{
  int i, t1 = 0, t2 = 1, t3;
  for (i = 1; i <= n; ++i) {
      t3 = t1 + t2;
      t1 = t2;
      t2 = t3;
  }
  return t1;
}


void ukol3()
{
  printf("CyklusforRekurze:%d\n", fibonaci(35));
  printf("FibonaciRekurze: %d\n", fibonaciRekurze(35));

}


int main(int argc, char *argv[])
{
  //ukol1();
  //ukol2();
  ukol3();
  return 0;
}

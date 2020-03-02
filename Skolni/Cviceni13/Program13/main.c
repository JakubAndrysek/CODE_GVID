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


int nacteniPole(int pole[], int velikostPole)
{
  for(int i = 0; i < velikostPole; i++)
  {
    scanf("%d", &pole[i]);
  }
}


void vypisPole(int pole[], int velikostPole)
{
  for(int i = 0; i < velikostPole; i++)
  {
    printf("%d ", pole[i]);
  }
  printf("\n");
}


void vypisPoleCarky(int pole[], int velikostPole)
{

  for(int i = 0; i < velikostPole-1; i++)
  {
    printf("%d, ", pole[i]);
  }

  printf("%d\n", pole[velikostPole-1]);

}


void ukol1()
{
  int velikostPole = 100;

  int pole[velikostPole];

  int nactiPrvku = 5;
  nacteniPole(pole, nactiPrvku);
  vypisPole(pole, nactiPrvku);
  vypisPoleCarky(pole, nactiPrvku);
}

bool jeVPoli(int pole[], int velikostPole, int hledej)
{
  for(int i = 0; i < velikostPole-1; i++)
  {
    if(pole[i] == hledej)
    {
      return true;
    }
  }
  return false;
}

void ukol2()
{
  int velikostPole = 100;

  int pole[velikostPole];

  int nactiPrvku = 5;
  nacteniPole(pole, nactiPrvku);

  int hledejPrvek = 8;
  if(jeVPoli(pole, nactiPrvku, hledejPrvek))
  {
    printf("Hledane cislo %d je obasezeno v poli -> ", hledejPrvek);
  }
  else
  {
    printf("Hledane cislo %d neni obasezeno v poli -> ", hledejPrvek);
  }
  vypisPoleCarky(pole, nactiPrvku);
}

int kopirujZPoleVetsiNez(int vstupPole[], int velikostPole, int vystupPole[], int vetsiNez)
{
  int index = 0;

  for(int i = 0; i < velikostPole; i++)
  {
    if(vstupPole[i] > vetsiNez)
    {
      vystupPole[index] = vstupPole[i];
      index++;
    }
  }
  return index;
}


void ukol3()
{
  int velikostPole = 100;
  int vstupPole[velikostPole];
  int vystupPole[velikostPole];

  int nactiPrvku = 5;
  nacteniPole(vstupPole, nactiPrvku);

  int vetsiNez = 3;

  printf("Toto je vstupni pole a hledam v nem prvky vetsi nez %d -> ", vetsiNez);
  vypisPoleCarky(vstupPole, nactiPrvku);

  int velikostNovehoPole = kopirujZPoleVetsiNez(vstupPole, nactiPrvku, vystupPole, vetsiNez);
  printf("\nNove pole obsahuje %d prvku a vypada takto -> ", velikostNovehoPole);
  vypisPoleCarky(vystupPole, velikostNovehoPole);
}

void vlozDoSerazenehoPole(int vstupPole[], int velikostPole, int vloz)
{
  //for(int x = velikostPole-1; x > -1)
  {

  }
}

/*
  for(int i = velikostPole; i >= 0; i--)
  {
    if(vstupPole[i-1] > vloz)
    {
      vystupPole[i] = vstupPole[i-1];
    }
    else
    {
      printf("%d, ", )
      //vystupPole[i+2] = vloz;
    }
    printf("%d, ", vstupPole[i]);

  }
*/


void ukol4()
{
  int velikostPole = 100;

  int pocetPrvku = 8;
  int vstupPole[] = {1, 8, 15, 16, 20, 28, 35, 100};



  int vloz = 12;

  vlozDoSerazenehoPole(vstupPole, pocetPrvku, vloz);
  printf("\nkonec\n");
  vypisPoleCarky(vstupPole, pocetPrvku+1);
}




void eratostenovoSito(int pole[], int velikostPole)
{
  pole[0] = pole[1] = 0;
  for(int i = 2; i < velikostPole; i++)
  {
    pole[i] = 1;
  }

  for(int i = 2; i < velikostPole; i++)
  {
    if(pole[i])
    {
      for(int x = i*2; x < velikostPole; x+=i)
      {
        pole[x] = 0;
        //printf("*%d*", i);
      }
    }
  }

  for(int x = 2; x < velikostPole; x++)
  {
    if(pole[x] == 1)
    {
      printf("%d, ", x);
    }
  }
}


void ukol5()
{
  int velikostPole = 10000;

  int vstupPole[velikostPole];

  eratostenovoSito(vstupPole, velikostPole);
}



int main()
{
  //ukol1();  //Nacteni a vypis pole
  //ukol2();  //hledej v poli
  //ukol3();  //Kopiruj do pole prvky vetsi nez
  //ukol4();  //vloz prvek do pole
  ukol5();  //Eratostenovo sito
  return 0;
}

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


void vypis(FILE* vstup, FILE* vystup)
{
  int znak;

  while((znak = fgetc(vstup)) != EOF)
  {
    printf("%c", znak);
  }

}


void kopie(FILE* vstup, FILE* vystup)
{
  int znak, pocet;

  while((znak = fgetc(vstup)) != EOF)
  {
    fputc(znak, vystup);
    pocet++;
  }
  printf("Konec kopie\n\n");

}


void kopieNahrad(FILE* vstup, FILE* vystup)
{
  int znak;

  while((znak = fgetc(vstup)) != EOF)
  {
    if(znak == '.')
    {
      fputc(';', vystup);
    }
    else
    {
      fputc(znak, vystup);
    }

  }
  printf("Konec kopie\n\n");

}


int pocetZanku(FILE* vstup)
{
  int znak, pocet;

  while((znak = fgetc(vstup)) != EOF)
  {
    pocet++;
  }
  printf("Konec pocitani\n\n");

  return pocet;

}






//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
  char cesta[256+1];


  FILE* fvstup = fopen("vstupni.txt", "r");
  FILE* fvystup = fopen("vystupni.txt", "w");

  if(fvstup == NULL)
  {
    printf("Nepodarilo se otevrit soubor\n");
    return 1;
  }

  if(fvystup == NULL)
  {
    printf("Nepodarilo se otevrit soubor\n");
    return 1;
  }


  /*1.*/
  //kopie(fvstup, fvystup);

  /*2*/
  //kopieNahrad(fvstup, fvystup);


  /*3*/
  //int pocetZ = pocetZanku(fvstup);
  //printf("Pocet znaku %d\n\n", pocetZ);


  fclose(fvstup);
  fclose(fvystup);
  return 0;
}

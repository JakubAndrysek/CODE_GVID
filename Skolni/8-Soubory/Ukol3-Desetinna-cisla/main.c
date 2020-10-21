/*
 * Projekt:
 * Autor: Jakub Andrysek
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // pro praci s typem bool a konstantami true a false

void cisla(FILE* vstup)
{
  float cislo;
  int pocitadlo = 0;
  float max, min;
  float prumer;
  bool poprve = true;

  while(fscanf(vstup, "%f ", &cislo)==1)
  {
    pocitadlo++;
    prumer += cislo;
    if(poprve)
    {
      max = cislo;
      min = cislo;
      poprve = false;
    }
    if(cislo>max)
    {
      max = cislo;
    }

    if(cislo<min)
    {
      min = cislo;
    }
  }

  prumer /= pocitadlo;
  printf("Maximalni hodnota je %.2f\n", max );
  printf("Minimalni hodnota je %.2f\n", min );
  printf("Prumerna hodnota je %.2f\n", prumer);
}

int main(void)
{
  FILE* vstup = fopen("Vstup.txt", "r");

  if(vstup == NULL)
  {
    printf("Chyba otevreni");
    return 1;
  }

  cisla(vstup);
  fclose(vstup);
  return 0;
}

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

void cesar(FILE* vstup, FILE* vystup, int posun)
{
  int znak;
  while((znak = fgetc(vstup))!= EOF)
  {


    if(znak >= 'a' && znak <= 'z')
    {
      if(znak+posun>'z')
      {
        fputc(znak+posun-('z'-'a')-1, vystup);
        printf("%c", znak+posun-('z'-'a')-1);
      }
      else if(znak+posun<'a')
      {
        fputc(znak+posun+('z'-'a')+1, vystup);
        printf("%c", znak+posun+('z'-'a'));
      }
      else
      {
        fputc(znak+posun, vystup);
        printf("%c", znak+posun);
      }
    }
    else
    {
      fputc(znak, vystup);
      printf("%c", znak);
    }
  }
}

int main(int argc, char *argv[])  // pro parametry prikazoveho radku
//int main(void)
{
  FILE* vstup = fopen("Vstup.txt", "r");
  FILE* vystup = fopen("Vystup.txt", "w");

  if(vstup == NULL)
  {
    printf("Chyba otevreni");
    return 1;
  }

  if(vystup == NULL)
  {
    printf("Chyba otevreni");
    return 1;
  }

  cesar(vstup, vystup, 3);

  fclose(vstup);
  fclose(vystup);

  return 0;
}

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

void naplnPole(char mpole[20][20], int rr)
{
  for(int r = 0; r < rr; r++)
  {
    for(int s = 0; s < rr; s++)
    {
      if(r == s)
      {
          mpole[r][s] = '*';
      }
      else if(s == rr-r-1)
      {
        mpole[r][s] = '*';

      }
      else
      {
        mpole[r][s] = '-';
      }

    }
  }
}


void vypisPole(char mpole[20][20], int rr)
{
  for(int r = 0; r < rr; r++)
  {
    for(int s = 0; s < rr; s++)
    {
      printf("%c ", mpole[r][s]);
    }
    printf("\n");
  }
}

int main(void)
{
  char pole[20][20];

  int r, s;



  do{
    printf("Zadej pocet radku: ");
    scanf("%d", &r);
  }while(r > 20);

  naplnPole(pole, r);

  vypisPole(pole, r);

  return 0;
}

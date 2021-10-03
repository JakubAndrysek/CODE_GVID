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

typedef struct{
  char jmeno[20];
  int znamky[5];
  float prumer;
}ZNAMKY;


//void znamky(FILE* vstup, FILE* vystup)
//{
//  ZNAMKY zn;
//  float vaha[] = {0.5, 0.25, 0.75, 1};
//
//  float vahaS = 0;
//  for(int i=0; i<4; i++)
//  {
//    vahaS += vaha[i];
//  }
//
//  while(fscanf(vstup, "%19s %d %d %d %d", zn.jmeno, &zn.a, &zn.b, &zn.c, &zn.d) == 5)
//  {
//    float znamkyS = zn.a * vaha[0] + zn.b*vaha[1] + zn.c*vaha[2] + zn.d*vaha[3];
//    zn.prumer = znamkyS/vahaS;
//    printf("%s -> %g -> %g\n", zn.jmeno, zn.prumer, round(zn.prumer));
//    fprintf(vystup, "%s -> %g -> %g\n", zn.jmeno, zn.prumer, round(zn.prumer));
//  }
//}

void znamky(FILE* vstup, FILE* vystup)
{
  ZNAMKY zn;

  float vaha[] = {0.5, 0.25, 0.75, 1};

  float vahaS = 0;
  for(int i=0; i<4; i++)
  {
    vahaS += vaha[i];
  }

  while(fscanf(vstup, "%19s %d %d %d %d", zn.jmeno, &zn.znamky[0], &zn.znamky[1], &zn.znamky[2], &zn.znamky[3]) == 5)
  {
    zn.prumer = 0;

    for(int i = 0; i<4; i++)
    {
      zn.prumer += vaha[i]*zn.znamky[i];
    }
    zn.prumer = zn.prumer/vahaS;
    printf("%s -> %g -> %g\n", zn.jmeno, zn.prumer, round(zn.prumer));
    fprintf(vystup, "%s -> %g -> %g\n", zn.jmeno, zn.prumer, round(zn.prumer));
  }
}

void pocetZnamek(FILE* vstup, FILE* vystup)
{
  ZNAMKY zn;
  ZNAMKY sum = {.znamky={0}};


  while(fscanf(vstup, "%19s %d %d %d %d", zn.jmeno, &zn.znamky[0], &zn.znamky[1], &zn.znamky[2], &zn.znamky[3]) == 5)
  {

    for(int i = 0; i<4; i++)
    {
      sum.znamky[zn.znamky[i]] ++;
    }
  }

  printf("\n\nPocet znamek:\n");

  for(int i = 0; i<=4; i++)
  {
    printf("%d -> %d \n", i+1, sum.znamky[i+1]);

  }
}


int main(void)
{
  FILE * vstup = fopen("vstup.txt", "r");
  FILE * vystup = fopen("vystup.txt", "w");

  if(vstup == NULL)
  {
    printf("Chuba otevreni programu");
    return 0;
  }

  if(vystup == NULL)
  {
    printf("Chuba otevreni programu");
    return 0;
  }


  znamky(vstup, vystup);

  rewind(vstup);

  pocetZnamek(vstup, vystup);

  fclose(vstup);
  fclose(vystup);

  return 0;
}

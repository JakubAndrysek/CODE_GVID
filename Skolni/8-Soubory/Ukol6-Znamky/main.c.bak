/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
 #include <string.h>  // pro praci s textovymi retezci
 #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

typedef struct{
  char jmeno[20];
  int m, cj, aj, ivt;
  float prumer;
  char prospel[20];
  char vyznamenani[20];
}ZNAMKY;

void znamky(FILE* vstup, FILE* vystup)
{
	ZNAMKY zak;

	while(fscanf(vstup, "%19s %d %d %d %d", zak.jmeno, &zak.m, &zak.cj, &zak.aj, &zak.ivt) == 5)
	{
		zak.prumer = (zak.aj+zak.cj+zak.ivt+zak.m)/4.0;
		strcpy(zak.vyznamenani, "");

		if(zak.aj==5 || zak.cj==5 || zak.ivt==5 || zak.m==5)
		{
			strcpy(zak.prospel, "neprospel/a");
		}
		else
		{
			strcpy(zak.prospel, "prospel/a");
			if(zak.prumer<=1.5 && zak.aj <= 2 && zak.cj<=2 && zak.ivt<=2 && zak.m<=2)
			{
				strcpy(zak.vyznamenani, "s vyznamenanim");
			}
		}
		dprintf("%s ma prumer [%d, %d, %d, %d] %.2f %s %s\n", zak.jmeno, zak.aj, zak.cj, zak.ivt, zak.m, zak.prumer, zak.prospel, zak.vyznamenani);
		fprintf(vystup, "%s ma prumer %.2f %s %s\n", zak.jmeno, zak.prumer, zak.prospel, zak.vyznamenani);
	}
		printf("Vypocitano");
}

int main(void)
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

  znamky(vstup, vystup);

  fclose(vstup);
  fclose(vystup);

  return 0;
}

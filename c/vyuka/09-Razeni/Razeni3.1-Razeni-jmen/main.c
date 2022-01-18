/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

typedef struct
{
	int den;
	int mesic;
	char jmeno[20];
}svatek;

int nacteniSouboruDoPoleStruktur(FILE* vstup, svatek svatky[])
{
	int i = 0;
	char jmeno;
	while(fscanf(vstup, "%d. %d.\t%s\n", svatky[i].den, svatky[i].mesic)==3)
//	while(fscanf(vstup, "%d. %d.\t%s", svatky[i].den)==1)
	{
		i++;
		dprintf( "%d. %d.\t%s\n", svatky[i].den, &svatky[i].mesic, svatky[i].jmeno);
//		dprintf( "%d. \n", svatky[i].den);
	}
//	strcpy(svatky[0].jmeno, "Kuba") ;
//
//	dprintf( "%d. %d.\t%s ", svatky[0].den, svatky[0].mesic, svatky[0].jmeno);
//	dprintf( "%d. %d.\t%s ", svatky[1].den, svatky[1].mesic, svatky[1].jmeno);
//	dprintf( "%d. %d.\t%c ", svatky[1].den);


	return 1;
}

void zapisPoleDoSouboru(FILE* vystup, int pole[], int pocet)
{
	for(int i = 0; i<pocet; i++)
	{
		printf("%d ", pole[i]);
		fprintf(vystup,"%d ", pole[i]);
	}
}

void vypisPole(int pole[], int pocet)
{
	for(int i = 0; i<pocet; i++)
	{
		printf("%2d ", pole[i]);
	}
}

void sort(int pole[], int pocet)
{
	int d, i, vkladany;

	for(int i = 0; i<pocet-1; i++)
	{
		for(int l = pocet-1; l>i;	 l--)
		{
			if(pole[l-1]>pole[l])
			{
				int pom = pole[l-1];
				pole[l-1] = pole[l];
				pole[l] = pom;
			}
		}
	}
}


int main(void)
{

	FILE* vstup = fopen("vstup.txt", "r");
	FILE* vystup = fopen("vystup.txt", "w");

	if(vstup == NULL)
	{
		printf("Soubor nelze otevrit");
		return 1;
	}

	if(vystup == NULL)
	{
		printf("Soubor nelze otevrit");
		return 1;
	}

//	svatek svatky[1010];
	svatek svatky[] =
		{
			{4, 7, "ASD"},
			{6, 8, "daesf"}
		};

	int pocet;


	pocet = nacteniSouboruDoPoleStruktur(vstup, svatky);

//	if(pocet<2)
//	{
//		printf("Molo prvku v souboru");
//		return 1;
//	}
//
//	sort(pole, pocet);
//
////	vypisPole(pole, pocet);
//
//	zapisPoleDoSouboru(vystup, pole, pocet);
//	printf("\n\nDokonceno");

	return 0;
}

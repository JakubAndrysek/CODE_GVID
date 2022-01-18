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


int nacteniSouboruDoPole(FILE* vstup, int pole[])
{
	int i = 0;
	while(fscanf(vstup, "%d ", &pole[i])==1)
	{
		i++;
	}

	return i;
}

void zapisPoleDoSouboru(FILE* vystup, int pole[], int pocet)
{
	for(int i = 0; i<pocet; i++)
	{
		fprintf(vystup,"%d ", pole[i]);
	}

}

void vypisPole(int pole[], int pocet)
{
	for(int i = 0; i<pocet; i++)
	{
		printf("%2d ", pole[i]);
	}
	printf("\n");
}


void rozdeleni(int pole[], int od, int po, int pivot, int *levy, int *pravy)
{
	*levy = od;
	*pravy = po;
	do
	{

		while (pole[*levy] < pivot && *levy < po)
		{
			++*levy;
		}
		while (pivot < pole[*pravy] && *pravy > od)
		{
			--*pravy;
		}

		if (*levy < *pravy)
		{
			int pom = pole[*levy];
			pole[*levy] = pole[*pravy];
			pole[*pravy] = pom;
		}

		if(*levy <= *pravy)
		{
			++*levy;
			--*pravy;
		}
	}while (*levy < *pravy);
}



void sort(int pole[], int od, int po)
{
	int levy;
	int pravy;

	if (od < po)
	{
//		int pivot = pole[(od + po)/2];
		int pivot = pole[po];

		rozdeleni(pole, od, po, pivot, &levy, &pravy);

		sort(pole, od, pravy);
		sort(pole, levy, po);
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

	int pole[1010];
	int pocet;


	pocet = nacteniSouboruDoPole(vstup, pole);

	if(pocet<2)
	{
		printf("Molo prvku v souboru");
		return 1;
	}

	vypisPole( pole, pocet);

	sort(pole, 0, pocet-1);


	vypisPole( pole, pocet);
	zapisPoleDoSouboru(vystup, pole, pocet);

	printf("\n\nDokonceno");

	return 0;
}

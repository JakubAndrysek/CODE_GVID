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

void zapisPoleDoSouboru(FILE* vstup, int pole[], int pocet, int zarazka)
{
	for(int i = 0; i<pocet; i++)
	{

		if(i == zarazka && zarazka != -1)
		{
			fprintf(vstup, "*%d  ", pole[i]);
		}
		else
		{
			fprintf(vstup, "%d  ", pole[i]);
		}
	}
	fprintf(vstup, "\n");
}

void vypisPole(int pole[], int pocet, int zarazka)
{
	for(int i = 0; i<pocet; i++)
	{

		if(i == zarazka && zarazka != -1)
		{
			printf("*%d ", pole[i]);
		}
		else
		{
			printf(" %d ", pole[i]);
		}
	}
	printf("\n");
}


void sort(FILE* vystup, int pole[], int pocet)
{
	int l, posledni, i = 0;

	for(int i = 0; i<pocet-1; i++)
	{
		int posledni = pocet-1;
		for(l = pocet-1; l>i; l--)
		{
			if(pole[l-1]>pole[l])
			{
				int pom = pole[l-1];
				pole[l-1] = pole[l];
				pole[l] = pom;
				posledni = l;
			}
		}
		i = posledni;
		vypisPole(pole, pocet, posledni);
		zapisPoleDoSouboru(vystup, pole, pocet, posledni);
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

	vypisPole( pole, pocet, -1);
	zapisPoleDoSouboru(vystup, pole, pocet, -1);

	sort(vystup, pole, pocet);

	vypisPole( pole, pocet, -1);
	zapisPoleDoSouboru(vystup, pole, pocet, -1);

	printf("\n\nDokonceno");

	return 0;
}

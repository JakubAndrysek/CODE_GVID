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



void sort(int pole[],int pomPole[], int od, int po) {
	if (od < po)
	{
		int stred = (od + po)/2;
		sort(pole, pomPole, od, stred);
		sort(pole, pomPole, stred+1, po);
		slevani(pole, pomPole, od, po);

		for(int i = od; i<=po; i++)
		{
			pole[i] = pomPole[i];
		}

	}
}

void slevani(int pole[], int pomPole[], int od, int po)
{
	int levy = od;
	int pom = od;
	int stred = (od+po)/2;
	int pravy = stred+1;

	while (levy <= stred && pravy <= po)
	{
		if(pole[levy] <= pole[pravy])
		{
			pomPole[pom++] = pole[levy++];
		}
		else
		{
			pomPole[pom++] = pole[pravy++];
		}
	}

	while(levy <= stred)
	{
		pomPole[pom++] = pole[levy++];
	}
	while(pravy <= po)
	{
		pomPole[pom++] = pole[pravy++];
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

	int pole[1000];
	int pomPole[1000];
	int pocet;


	pocet = nacteniSouboruDoPole(vstup, pole);

	if(pocet<2)
	{
		printf("Molo prvku v souboru");
		return 1;
	}

	vypisPole( pole, pocet);

	sort(pole, pomPole, 0, pocet-1);


	vypisPole( pole, pocet);
	zapisPoleDoSouboru(vystup, pole, pocet);

	printf("\n\nDokonceno");

	return 0;
}

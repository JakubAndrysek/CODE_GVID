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


int nacteniSouboruDoPole(FILE* vstup, int pole[], int limit)
{
	int i = 0;
	while(i<limit && fscanf(vstup, "%d ", &pole[i])==1)
	{
		i++;
	}
	return i;
}

void vypisPole(int pole[], int pocet)
{
	for(int i = 0; i<pocet; i++)
	{
		printf("%2d ", pole[i]);
	}
}

int hledej(int pole[], int leva, int prava, int hledane)
{
	int stred;
	while (leva <= prava) {
		stred = (leva+prava)/2;
		printf("Stred = %d\n", stred);
		if(pole[stred] == hledane){
			return stred;
		}
		if(pole[stred] < hledane) {
			leva = stred+1;
		}
		else {
			prava = stred-1;
		}
	}
	return -1;
}

#define MAX 30

int main(void)
{

	FILE* vstup = fopen("vstup.txt", "r");

	if(vstup == NULL)
	{
		printf("Soubor nelze otevrit");
		return 1;
	}

	int pole[MAX];
	int pocet;


	pocet = nacteniSouboruDoPole(vstup, pole, MAX);

	vypisPole(pole, pocet);


	int hledane;

	printf("\nZadej hledane cislo: ");
	scanf("%d", &hledane);

	int pozice = hledej(pole, 0, pocet, hledane);

	if(pozice>=0)
	{
		printf("Cislo %d nalezeno na indexu %d", hledane, pozice);
	}
	else{
		printf("Cislo %d nebylo nalezeno v souboru", hledane);
	}


	return 0;
}
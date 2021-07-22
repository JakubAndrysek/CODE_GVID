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


int nacteniSouboruDoPole(FILE* vstup, int pole[])
{
	int i = 0;
	while(fscanf(vstup, "%d ", &pole[i])==1)
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

int hledej(int pole[], int pocet, int hledane)
{

	for(int i = 0; i<pocet-1; i++)
	{
		if(pole[i] == hledane){
			return i;
		}
	}
	return -1;
}


int main(void)
{

	FILE* vstup = fopen("vstup.txt", "r");

	if(vstup == NULL)
	{
		printf("Soubor nelze otevrit");
		return 1;
	}

	int pole[1010];
	int pocet;


	pocet = nacteniSouboruDoPole(vstup, pole);

	vypisPole(pole, pocet);


	int hledane;

	printf("\nZadej hledane cislo: ");
	scanf("%d", &hledane);

	int pozice = hledej(pole, pocet, hledane);

	if(pozice>=0)
	{
		printf("Cislo %d nalezeno na indexu %d", hledane, pozice);
	}
	else{
		printf("Cislo %d nebylo nalezeno v souboru", hledane);
	}


	return 0;
}

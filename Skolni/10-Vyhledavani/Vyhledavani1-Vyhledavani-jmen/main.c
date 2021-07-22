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
	char jmeno[30];
}SVATEK;


int nacteniSouboruDoPoleStruktur(FILE* vstup, SVATEK svatky[600])
{
	int i = 0;

	while(fscanf(vstup, "%d. %d. %29s ", &svatky[i].den, &svatky[i].mesic, svatky[i].jmeno)==3)
	{

//		dprintf( "%d. %d.\t%s\n", svatky[i].den, svatky[i].mesic, svatky[i].jmeno);
		i++;
	}

	return i;
}

int hledej(SVATEK svatky[600], int pocet, char hledany[30])
{

	for(int i = 0; i<pocet-1; i++)
	{
		if(strcmp(svatky[i].jmeno, hledany)==0){
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


	int pocet;

	SVATEK svatky[600];

	pocet = nacteniSouboruDoPoleStruktur(vstup, svatky);


	int hledane[30];

	printf("Zadej hledane jmeno: ");
	scanf("%29s", hledane);

	int index = hledej(svatky, pocet, hledane);

	if(index>=0){
		printf("Jmeno %s nalezeno na indexu %d", hledane, index);
	}
	else{
		printf("Jmeno %s nebylo nalezeno", hledane);
	}

	return 0;
}

/*
 * Projekt:
 * Autor: Jakub Andrysek
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
 #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

#include "seznam.h"


//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
//	char nazev[31];
//	printf("Zadej nazav souboru:");
//	scanf("%30s", nazev);
//	FILE * fVstup = fopen(nazev, "r");
//
////	FILE * fVstup = fopen("data.txt", "r");
//	if(fVstup == NULL) {
//		printf("Soubor se nepodarilo otevrit\n");
//		return 2;
//	}

	Tseznam * seznam = seznamInitD();
	seznamInsert(seznam, 1);
	seznamInsert(seznam, 2);

	seznamV

//	fclose(fVstup);
	return 0;
}

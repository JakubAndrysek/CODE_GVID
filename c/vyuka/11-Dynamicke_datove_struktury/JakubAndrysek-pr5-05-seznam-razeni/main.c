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

bool seradPrvkyDoSeznamu(FILE * fVstup, Tseznam * sez) {
	float pomNact;
	while(fscanf(fVstup, "%f", &pomNact) == 1) {
		if(isEmpty(sez)) {
			seznamInsert(sez, pomNact);
		} else {
			float pom;
			current(sez, &pom);
			while(pomNact <= pom) {
				seznamInsert(sez, pom);
				break;
			}

		}
		seznamVypis(sez);
	}



}


//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void) {
//	char nazev[31];
//	printf("Zadej nazav souboru:");
//	scanf("%30s", nazev);
//	FILE * fVstup = fopen(nazev, "r");

	FILE * fVstup = fopen("data10.txt", "r");
	if(fVstup == NULL) {
		printf("Soubor se nepodarilo otevrit\n");
		return 2;
	}

	Tseznam * seznam = seznamInitD();

	if(seradPrvkyDoSeznamu(fVstup, seznam)) {
		printf("Serazene prvky:\n");
		seznamVypis(seznam);
	} else {
		printf("Neni co vypsat\n");
	}


	seznamFree(seznam);
	fclose(fVstup);
	return 0;
}

//	float pom;
//
//	Tseznam * seznam = seznamInitD();
//	seznamInsert(seznam, 1);
//	seznamInsert(seznam, 2);
//	seznamInsert(seznam, 3);
//	seznamInsert(seznam, 4);
//	seznamInsert(seznam, 5);
//	seznamInsert(seznam, 6);
//
//	seznamVypis(seznam);
//
//	current(seznam, &pom);
//	printf("Curr: %g\n", pom);
//
//	seznamRemove(seznam, &pom);
//	printf("Rem: %g\n", pom);
//
//	seznamVypis(seznam);
//
//	seznamRemove(seznam, &pom);
//	printf("Rem: %g\n", pom);
//
//	seznamVypis(seznam);
//
//	seznamFree(seznam);
//
//	seznamVypis(seznam);

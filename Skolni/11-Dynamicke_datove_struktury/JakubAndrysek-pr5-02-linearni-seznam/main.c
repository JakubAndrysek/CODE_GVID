/*
 * Projekt:
 * Autor: Jakub Andrysek
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

typedef struct _prvek Tprvek;

struct _prvek {
	float hodnota;
	Tprvek * dalsi;
};

Tprvek * novyPrvek(float cislo) {
	Tprvek * prvek = malloc(sizeof(Tprvek));

	if(prvek == NULL) {
		return NULL;
	}

	prvek->hodnota = cislo;
	prvek->dalsi = NULL;

	return prvek;
}

Tprvek * vlozNaZacetek(float cislo, Tprvek * prvniPrvek) {
	Tprvek* novy = novyPrvek(cislo);
	if(novy == NULL) {
		return NULL;
	}
	novy->dalsi = prvniPrvek;
	return novy;
}

void vypisPrvky(Tprvek * prvniPrvek) {
	Tprvek * prvek = prvniPrvek;

	while (prvek != NULL) {
		printf("%g\n", prvek->hodnota);
		prvek = prvek->dalsi;
	}
}

Tprvek * otocPole(Tprvek * prvniPrvek) {
	Tprvek * predchozi = NULL;
	Tprvek * aktualni = prvniPrvek;
	Tprvek * dalsi = NULL;

	while (aktualni != NULL) {
		dalsi = aktualni->dalsi;
		aktualni->dalsi = predchozi;
		predchozi = aktualni;
		aktualni = dalsi;
	}

	prvniPrvek = predchozi;
	return predchozi;
}

void zrusSeznam(Tprvek * prvniPrvek) {
	Tprvek * prvek = prvniPrvek;

	while (prvek != NULL) {
		Tprvek * prvekDalsi = prvek->dalsi;
		free(prvek);
		prvek = prvekDalsi;
	}
}


Tprvek * nactiSoubor(FILE * fVstup) {
	float cislo;
	Tprvek * prvek;

	if(fscanf(fVstup, "%f", &cislo)!=1) {
		return NULL;
	}
	else {
		if((prvek = vlozNaZacetek(cislo, NULL))==NULL) {
			return NULL;
		}
	}

	while(fscanf(fVstup, "%f", &cislo)==1) {
		if((prvek = vlozNaZacetek(cislo, prvek))==NULL) {
			return NULL;
		}
	}
	return prvek;
}

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
	char nazev[31];
	printf("Zadej nazav souboru:");
	scanf("%30s", nazev);
	FILE * fVstup = fopen(nazev, "r");

//	FILE * fVstup = fopen("data10.txt", "r");

	if (fVstup == NULL) {
		printf("Pozadovany soubor se nepodarilo otevrit\n");
		return -1;
	}

	Tprvek * prvniPrvek = nactiSoubor(fVstup);
	if(prvniPrvek == NULL) {
		printf("Nepodarila se alokovat pamet!\n");
		return -1;
	}

	printf("Nactene prvky:\n");
	vypisPrvky(prvniPrvek);

	printf("Opacne poradi:\n");
	prvniPrvek = otocPole(prvniPrvek);
	vypisPrvky(prvniPrvek);


	printf("Cisteni seznamu\n");
	zrusSeznam(prvniPrvek);

	fclose(fVstup);

	return 0;
}

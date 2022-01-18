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


typedef struct _prvek Tprvek;

struct _prvek {
	float hodnota;
	Tprvek * dalsi;
};

typedef struct {
	Tprvek* prvni;
	Tprvek* posledni;
	int delka;
	int maxDelka;
} Tfronta;

Tfronta* frInitD(int maxDelka){
	Tfronta* z = malloc(sizeof(Tfronta));
	if(z == NULL) {
		return NULL;
	}
	z->prvni= NULL;
	z->posledni= NULL;
	z->delka = 0;
	z->maxDelka = maxDelka;
	return z;
}

Tprvek* prvekNovy(float hodnota) {
	Tprvek* novy=malloc(sizeof(Tprvek));
	if (novy != NULL) {
		novy->hodnota = hodnota;
		novy->dalsi = NULL;
	}
	return novy;
}

bool frDequeue(Tfronta * fronta, float * hodnota) {
	if(fronta->prvni == NULL && fronta->posledni == NULL) {
		return false;
	}else {
		*hodnota = fronta->prvni->hodnota;
		Tprvek * pom = fronta->prvni;
		fronta->prvni = fronta->prvni->dalsi;
		free(pom);
		if(fronta->prvni == NULL) {
			fronta->posledni = NULL;
		}
		fronta->delka--;
		return true;
	}
}

void frEnqueue(Tfronta * fronta, float hodnota) {
	Tprvek* novy = prvekNovy(hodnota);
	if(novy == NULL) {
		return NULL;
	}

	if(fronta->delka >= fronta->maxDelka) {
		float pom;
		frDequeue(fronta, &pom);
//		printf("odebrat posledni\n");
	}

	if(fronta->prvni == NULL && fronta->posledni == NULL) {
		fronta->prvni = novy;
		fronta->posledni = novy;
		fronta->delka++;
	}else {
		fronta->posledni->dalsi = novy;
		fronta->posledni = novy;
		fronta->delka++;
	}

}


void frVypis(Tfronta * fronta) {
	Tprvek * prvek = fronta->prvni;

	while (prvek != NULL) {
		printf("%g\n", prvek->hodnota);
		prvek = prvek->dalsi;
	}
}


void frZrus(Tfronta * fronta) {
	float prvek;
	while(frDequeue(fronta, &prvek)) {;}
	free(fronta);
}

void prutokac(FILE * fVstup, int pocetPrvku) {
	Tfronta * fronta;
	if((fronta = frInitD(pocetPrvku)) == NULL) {
		printf("Nepovedla se inicializace\n");
		return 1;
	}
	float cislo;
	while(fscanf(fVstup, "%f", &cislo)==1) {
		frEnqueue(fronta, cislo);
	}

	frVypis(fronta);

	frZrus(fronta);
}

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
	char nazev[31];
	printf("Zadej nazav souboru:");
	scanf("%30s", nazev);
	FILE * fVstup = fopen(nazev, "r");

//	FILE * fVstup = fopen("data.txt", "r");
	if(fVstup == NULL) {
		printf("Soubor se nepodarilo otevrit\n");
		return 2;
	}

	int pocetPrvku;
	printf("Zadej pocet prvku k zobrazeni:");
	scanf("%d", &pocetPrvku);

	prutokac(fVstup, pocetPrvku);

	fclose(fVstup);
	return 0;
}

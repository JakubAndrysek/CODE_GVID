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

Tfronta* frInitD(void){
	Tfronta* z = malloc(sizeof(Tfronta));
	if(z == NULL) {
		return NULL;
	}
	z->prvni= NULL;
	z->posledni= NULL;
	z->delka = 0;
	z->maxDelka = 0;
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

void frEnqueue(float hodnota, Tfronta * fronta) {
	Tprvek* novy = prvekNovy(hodnota);
	if(novy == NULL) {
		return NULL;
	}

	if(fronta->delka > fronta->maxDelka) {
		//odebrat posledni
		printf("odebrat posledni\n");
	}

	if(fronta->prvni == NULL && fronta->posledni == NULL) {
		fronta->prvni = novy;
		fronta->posledni = novy;
		fronta++;
	}else {
		fronta->posledni->dalsi = novy;
		fronta->posledni = novy;
		fronta++;
	}

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
		return true;
	}
}


void vypisPrvky(Tfronta * fronta) {
	Tprvek * prvek = fronta->prvni;

	while (prvek != NULL) {
		printf("%g\n", prvek->hodnota);
		prvek = prvek->dalsi;
	}
}


void zrusFrontu(Tprvek * prvniPrvek) {
	float prvek;
	while(frDequeue(prvniPrvek, &prvek)) {
	;
	}
}

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
//	char nazev[31];
//	printf("Zadej nazav souboru:");
//	scanf("%30s", nazev);
//	FILE * fVstup = fopen(nazev, "r");

//	FILE * fVstup = fopen("data10.txt", "r");

	Tfronta * fronta;
	if((fronta = frInitD()) == NULL) {
		printf("Nepovedla se inicializace\n");
		return 1;
	}

	frEnqueue(8.35, fronta);
	frEnqueue(1.23, fronta);
	frEnqueue(6.73, fronta);

	vypisPrvky(fronta);

	float x;
	x = 5;

//	int a = frDequeue(fronta, &x);
//	a = frDequeue(fronta, &x);
//	a = frDequeue(fronta, &x);
	zrusFrontu(fronta);

	vypisPrvky(fronta);


//	if (fVstup == NULL) {
//		printf("Pozadovany soubor se nepodarilo otevrit\n");
//		return -1;
//	}
//
//	Tprvek * prvniPrvek = nactiSoubor(fVstup);
//	if(prvniPrvek == NULL) {
//		printf("Nepodarila se alokovat pamet!\n");
//		return -1;
//	}
//
//
//	zrusSeznam(prvniPrvek);
//
//	fclose(fVstup);

	return 0;
}



//////////////

//Tprvek * nactiSoubor(FILE * fVstup) {
//	float cislo;
//	Tprvek * prvek;
//
//	if(fscanf(fVstup, "%f", &cislo)!=1) {
//		return NULL;
//	}
//	else {
//		if((prvek = push(cislo, NULL))==NULL) {
//			return NULL;
//		}
//	}
//
//	while(fscanf(fVstup, "%f", &cislo)==1) {
//		if((prvek = push(cislo, prvek))==NULL) {
//			return NULL;
//		}
//	}
//	return prvek;
//}


//typedef struct _prvek Tprvek;
//
//struct _prvek {
//	char hodnota;
//	Tprvek * dalsi;
//};
//
//typedef struct {
//	Tprvek* vrchol;
//	int vyska;
//} Tzasobnik;
//

//
//
//
////int main(int argc, char *argv[])  // pro parametry prikazoveho radku
//int main(void)
//{
//	zasInitD()
//  	return 0;
//}

//Tprvek * otocPole(Tprvek * prvniPrvek) {
//	Tprvek * predchozi = NULL;
//	Tprvek * aktualni = prvniPrvek;
//	Tprvek * dalsi = NULL;
//
//	while (aktualni != NULL) {
//		dalsi = aktualni->dalsi;
//		aktualni->dalsi = predchozi;
//		predchozi = aktualni;
//		aktualni = dalsi;
//	}
//
//	prvniPrvek = predchozi;
//	return predchozi;
//}

/*
 * Projekt:
 * Autor:
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
	char hodnota;
	Tprvek * dalsi;
};

typedef struct {
	Tprvek* vrchol;
	int vyska;
} Tzasobnik;

Tzasobnik* zasInitD(void){
	Tzasobnik* z = malloc(sizeof(Tzasobnik));
	if(z == NULL) {
		return NULL;
	}
	z->vrchol = NULL;
	z->vyska = 0;
	return z;
}

Tprvek* prvekNovy(char hodnota) {
	Tprvek* novy=malloc(sizeof(Tprvek));
	if (novy != NULL) {
		novy->hodnota = hodnota;
		novy->dalsi = NULL;
	}
	return novy;
}

void push(char hodnota, Tzasobnik * zasobnik) {
	Tprvek* novy = prvekNovy(hodnota);
	if(novy == NULL) {
		return NULL;
	}
	if(zasobnik->vrchol == NULL) {
		zasobnik->vrchol = novy;
	} else {
		novy->dalsi = zasobnik->vrchol;
		zasobnik->vrchol = novy;
	}
}

char pop(Tzasobnik * zasobnik) {
//	Tprvek * novyVrchol = zasobnik->vrchol;
	char smazanyPrvek = zasobnik->vrchol;
	Tprvek * smazanyVrch = zasobnik->vrchol;
	zasobnik->vrchol = zasobnik->vrchol->dalsi;
	free(smazanyVrch);
	return smazanyPrvek;
}

void vypisPrvky(Tzasobnik * zasobnik) {
	Tprvek * prvek = zasobnik->vrchol;

	while (prvek != NULL) {
		printf("%c\n", prvek->hodnota);
		prvek = prvek->dalsi;
	}
}


void zrusSeznam(Tprvek * prvniPrvek) {
	Tprvek * prvek = prvniPrvek;

	while (prvek != NULL) {
		Tprvek * prvekDalsi = prvek->dalsi;
		free(prvek);
		prvek = prvekDalsi;
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

	Tzasobnik * zasobnik = zasInitD();

	push('a', zasobnik);
	push('b', zasobnik);
	push('c', zasobnik);
	pop(zasobnik);
	push('d', zasobnik);

	vypisPrvky(zasobnik);


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

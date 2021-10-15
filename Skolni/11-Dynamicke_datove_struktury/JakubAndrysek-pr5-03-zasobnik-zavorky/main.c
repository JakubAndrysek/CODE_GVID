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

char zavOtev[] = {'[', '{', '('};
char zavZav[] = {']', '}', ')'};
int zavorDelka = 3;

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

bool zasPush(Tzasobnik * zasobnik, char hodnota) {
	Tprvek* novy = prvekNovy(hodnota);
	if(novy == NULL) {
		return false;
	}
	if(zasobnik->vrchol == NULL) {
		zasobnik->vrchol = novy;
	} else {
		novy->dalsi = zasobnik->vrchol;
		zasobnik->vrchol = novy;
	}
	return true;
}

bool zasPop(Tzasobnik * zasobnik, char * data) {
	if(zasobnik->vrchol == NULL) {
		return false;
	}
	*data = zasobnik->vrchol->hodnota;
	Tprvek * smazanyVrch = zasobnik->vrchol;
	zasobnik->vrchol = zasobnik->vrchol->dalsi;
	free(smazanyVrch);
	return true;
}

void zasVypis(Tzasobnik * zasobnik) {
	Tprvek * prvek = zasobnik->vrchol;

	while (prvek != NULL) {
		printf("%c\n", prvek->hodnota);
		prvek = prvek->dalsi;
	}
}

bool zasZrus(Tzasobnik * zasobnik) {
	if(zasobnik == NULL) {
		return false;
	}
	char pom;
	while(zasPop(zasobnik, &pom)) {;}
	free(zasobnik);
	return true;
}

int jeZavorka(char typ[], char zavorka) {
	for(int i = 0; i<zavorDelka; i++) {
		if(zavorka == typ[i]) {
			return i;
		}
	}
	return -1;
}

bool kontrolaZavorek(FILE * fVstup) {
	Tzasobnik * zas = zasInitD();
	char znak;
	int zavPozOte;
	int zavPozZav;
	while(fscanf(fVstup, "%c", &znak)==1) {
		if(jeZavorka(zavOtev, znak)!= -1) {
			zasPush(zas, znak);
		} else if ((zavPozZav = jeZavorka(zavZav, znak))!= -1) {
			char pom;
			if (!zasPop(zas, &pom)) {
				return false;
			}
			zavPozOte = jeZavorka(zavOtev, pom);
			if (zavPozOte != zavPozZav) {
				printf("<- CHYBA patri sem: %c\n", zavZav[zavPozZav]);
				return false;
			}
		}
		printf("%c", znak);
	}

	zasVypis(zas);

	if(zas->vrchol != NULL) {
		return false;
	}

	zasZrus(zas);
	return true;
}

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
	char nazev[31];
	printf("Zadej nazav souboru:");
	scanf("%30s", nazev);
	FILE * fVstup = fopen(nazev, "r");

//	FILE * fVstup = fopen("data-not-ok2.txt", "r");
////	FILE * fVstup = fopen("data-ok.txt", "r");

	if (fVstup == NULL) {
		printf("Pozadovany soubor se nepodarilo otevrit\n");
		return -1;
	}

	bool jeOK = kontrolaZavorek(fVstup);

	if(jeOK) {
		printf("\nZavorky jsou spravne\n");
	} else {
		printf("\nZavorky nejsou jsou spravne\n");
	}

	fclose(fVstup);

	return 0;
}

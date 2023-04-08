#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _prvek Tprvek;

struct _prvek {
	int hodnota;
	Tprvek* dalsi;
};

typedef struct {
	int vyska;
	Tprvek* vrchol;
} Tzasobnik;

Tzasobnik* zasVytvor() {
	Tzasobnik* zasobnik = malloc(sizeof(Tzasobnik));
	if (zasobnik == NULL) {
		printf("Failed to allocate");
		return NULL;
	}

	zasobnik->vrchol = NULL;
	zasobnik->vyska = 0;
	return zasobnik;
}



bool zasPush(Tzasobnik* zas, int hodnota) {
	if(zas == NULL) return false;

	Tprvek* prvek = malloc(sizeof(Tprvek));
	if (prvek == NULL) {
		printf("ZAS Nepodarilo se pridat\n");
		return false;
	}

	prvek->dalsi = zas->vrchol; // mel by byt NULL
	prvek->hodnota = hodnota;

	zas->vrchol = prvek;
	zas->vyska++;
	return true;
}

bool zasPop(Tzasobnik *zas, int *hodnota) {
	if(zas == NULL) return false;
	if(zas->vrchol == NULL) {
		printf("ZAS je prazdny\n");
		return false;
	}

	*hodnota = zas->vrchol->hodnota;

	Tprvek* naSmazani = zas->vrchol;


	// preklenuti
	zas->vrchol = zas->vrchol->dalsi;
	zas->vyska--;

	free(naSmazani);
	return true;
}

bool zasTop(Tzasobnik* zas, int* hodnota) {
	if(zas == NULL) return false;
	if(zas->vrchol == NULL) {
		printf("ZAS je prazdny\n");
		return false;
	}

	*hodnota = zas->vrchol->hodnota;
	return true;
}

int zasVyska(Tzasobnik* zas) {
	return zas->vyska;
}

void zasZrus(Tzasobnik* zas) {
	int hodnota;
	while (zasPop(zas, &hodnota)) {
		;
	}

	free(zas);
	zas = NULL;
	printf("ZAS zruseno\n");
}


int testFunkcnosti() {
	Tzasobnik* zas = zasVytvor();
	if(zas == NULL) {
		printf("ZAS ERR");
		return EXIT_FAILURE;
	}

	zasPush(zas, 55);

	int hodnota;
	if(!zasPop(zas, &hodnota)) {
		printf("ZAS ERR pop");
		return EXIT_FAILURE;
	}
	printf("ZAS pop: %d (melo by byt 55)\n", hodnota);


	// mel by byt prazdny
	if(zasPop(zas, &hodnota)) {
		printf("ZAS ERR mel by byt prazdny");
		return EXIT_FAILURE;
	}

	// mel by byt prazdny - znovu
	if(zasPop(zas, &hodnota)) {
		printf("ZAS ERR mel by byt prazdny");
		return EXIT_FAILURE;
	}


	zasPush(zas, 30);
	zasPush(zas, 31);
	zasPush(zas, 32);

	int hodnotaCteni;
	while(zasPop(zas, &hodnotaCteni)) {
		printf("ZAS pop: %d (30-32)\n", hodnotaCteni);
	}

	zasZrus(zas);
	return EXIT_SUCCESS;
}

bool jeOteviraciZav(char znak) {
	switch (znak) {
		case '(':
		case '{':
		case '[':
			return true;
	}
	return false;
}

bool jeZaviraciZav(char znak) {
	switch (znak) {
		case ')':
		case '}':
		case ']':
			return true;
	}
	return false;
}

bool zkontrolujZav(char otev, char zav) {
	if (otev == '{' && zav == '}') {
		return true;
	} else if (otev == '(' && zav == ')') {
		return true;
	} else if (otev == '[' && zav == ']') {
		return true;
	}
	return false;
}


void kontrolaZavorek() {
	Tzasobnik* zas = zasVytvor();

	FILE* f = fopen("zavorky.txt", "r");
	if(f == NULL) {
		printf("ZAVORKY err open\n");
		return;
	}

	char znak;
	while(fscanf(f, "%c", &znak) == 1) {
		if(jeOteviraciZav(znak)) {
			zasPush(zas, znak);
		} else if(jeZaviraciZav(znak)) {
			int oteviraciZav;
			zasPop(zas, &oteviraciZav);

			if(!zkontrolujZav(oteviraciZav, znak)) {
				printf("ZAVORKY se krizi\n");
				return;
			}
		}
	}

	if(!(zasVyska(zas) == 0)) {
		printf("ZAVORKY nesedi\n");
	}

	int hodnotaCteni;
	while(zasPop(zas, &hodnotaCteni)) {
		printf("ZAS pop: %c\n", hodnotaCteni);
	}

	return;
}



int main() {

	// testFunkcnosti();
	kontrolaZavorek();

	return 0;
}
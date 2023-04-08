#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum tchyby {EOK, EDUPKLIC, EPAMET, ENECEKANA};

typedef struct _uzel Tuzel;

struct _uzel {
	int klic;
	Tuzel *levy;
	Tuzel *pravy;
};

typedef struct {
	Tuzel *koren;
	int vaha;
} Tstrom;


Tstrom* bvsInit() {
	Tstrom *strom = malloc(sizeof(Tstrom));
	if (strom == NULL) {
		printf("Failed to allocate BVS\n");
		return NULL;
	}
	strom->koren = NULL;
	strom->vaha = 0;
	return strom;
}

void _bvsZrusPostorder(Tuzel *uzel) {
	if(uzel ==NULL) {
		return;
	}
	_bvsZrusPostorder(uzel->levy);
	_bvsZrusPostorder(uzel->pravy);
	free(uzel);
}

void bvsZrus(Tstrom *strom) {
	_bvsZrusPostorder(strom->koren);

	free(strom);
}

Tuzel* bvsNovyUzel(int klic) {
	Tuzel *uzel = malloc(sizeof(Tuzel));
	if(uzel != NULL) {
		uzel->klic = klic;
		uzel->levy = NULL;
		uzel->pravy = NULL;
	} else {
		printf("BVS - Error: Failed to allocate NovyUzel\n");
	}
	return uzel;
}

int _bvsVlozKlic(Tuzel **koren, int klic) {

	Tuzel *pom = *koren;

	if(pom == NULL) {
		printf("BVS - primo\n");
		pom = bvsNovyUzel(klic);
		if(pom == NULL)  {
			return EPAMET;
		}
		*koren = pom; // NUTNÉ!!! pom je lokální
		return EOK;
	}

	if(pom->klic == klic) {
		printf("BVS - Error: duplicitni klic\n");
		return EDUPKLIC;
	}

	if(klic < pom->klic) {
		printf("BVS <- levy\n");
		return _bvsVlozKlic(&pom->levy, klic);
	} else {
		printf("BVS -> pravy\n");
		return _bvsVlozKlic(&pom->pravy, klic);
	}
}

int bvsVlozKlic(Tstrom *strom, int klic) {
	printf("\nBVS - vkladam klic: %d\n", klic);

	int kod = _bvsVlozKlic(&strom->koren, klic);
	if(kod == EOK) {
		strom->vaha++;
	}
	return kod;
}


void _bvsPruchodInorder(Tuzel *uzel) {
	if(uzel != NULL) {
		_bvsPruchodInorder(uzel->levy);
		printf("\nIN: %d\n",uzel->klic);
		_bvsPruchodInorder(uzel->pravy);
	}
}


void bvsPruchodInorder(Tstrom *strom) {
	_bvsPruchodInorder(strom->koren);
}

Tuzel* _bvsHledejKlicPreorder(Tuzel *koren, int klic) {
	if(koren == NULL) { // Je ukazatel na kořen roven NULL?
		return NULL;
	}

	if(koren->klic == klic) { // Je klíč shodný s klíčem kořene?
		return koren;
	}

	if(klic < koren->klic) {
		_bvsHledejKlicPreorder(koren->levy, klic); // Je klíč menší než klíč kořene?
	} else {
		_bvsHledejKlicPreorder(koren->pravy, klic); // Je klíč větší než klíč kořene?
	}
}

Tuzel* bvsHledejKlic(Tstrom *strom, int klic) {
	return _bvsHledejKlicPreorder(strom->koren, klic);
}

void errCodeToText(int errorCode) {
	switch(errorCode) {
		case EOK:
			printf("--> OK\n");
			break;
		case EDUPKLIC:
			printf("--> Duplicitni klic\n");
			break;
		case EPAMET:
			printf("--> Nepodarilo se alokovat pamet\n");
			break;
		default:
			printf("--> Neznama chyba\n");
			break;
	};
}




void basicTest() {
	Tstrom *strom = bvsInit();

	errCodeToText(bvsVlozKlic(strom, 5));
	errCodeToText(bvsVlozKlic(strom, 5));

	errCodeToText(bvsVlozKlic(strom, 2));

	errCodeToText(bvsVlozKlic(strom, 3));
	errCodeToText(bvsVlozKlic(strom, 8));

	bvsPruchodInorder(strom);


	Tuzel *hledany = bvsHledejKlic(strom, 3);


	bvsZrus(strom);
	printf("Testing\n");
}

int main() {

	basicTest();
	return 0;
}
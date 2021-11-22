#include "seznam.h"

Tprvek * novyPrvek(float hodnota) {
	Tprvek * prvek = malloc(sizeof(Tprvek));
	if(prvek != NULL) {
		prvek->hodnota = hodnota;
		prvek->pred = NULL;
		prvek->dalsi = NULL;
	}
	return prvek;
}

Tseznam* seznamInitD() {
	Tseznam * sez = malloc(sizeof(Tseznam));
	if(sez != NULL) {
		sez->zacatek = NULL;
		sez->aktualni = NULL;
		sez->indexAktualniho = -1;
		sez->delka = 0;
	}
	return sez;
}

void seznamFree(Tseznam *sez) {
	float pom;
	while(!isEmpty(sez)) {
		seznamRemove(sez, &pom);
	}
}


bool seznamInsert(Tseznam* sez, float hodnota) {
	Tprvek * nPrvek;
	if((nPrvek = novyPrvek(hodnota)) == NULL) {
		return false;
	}
	Tprvek * aktual = sez->aktualni;

	if(isEmpty(sez)) { // prazdny seznam
		nPrvek->dalsi = nPrvek;
		nPrvek->pred = nPrvek;
		aktual = nPrvek;
		sez->zacatek = nPrvek;
	}else if(sez->aktualni == sez->zacatek) { // jeden prvek
		aktual->dalsi = nPrvek;
		nPrvek->pred = aktual;
		aktual->pred = nPrvek;
		nPrvek->dalsi = aktual;
	} else { // 2 a vice prvku
		nPrvek->pred = sez->aktualni;
		nPrvek->dalsi = sez->aktualni->dalsi;
		sez->aktualni->dalsi->pred = nPrvek;
		sez->aktualni->dalsi = nPrvek;
	}
	sez->aktualni = nPrvek;
	return true;
}


bool isEmpty(Tseznam* sez) {
	return ((sez == NULL) || (sez->zacatek == NULL) || (sez->aktualni == NULL));
}

//
//bool seznamRemove(Tseznam* sez, float* x) {
//	if(isEmpty(sez)) {
//		printf("Neni co vymazat\n");
//		return false;
//	}
//	*x = sez->aktualni->dalsi->hodnota;
//
//	if(sez->aktualni == sez->zacatek) {
//		sez->zacatek = NULL;
//		sez->aktualni = NULL;
//		sez->indexAktualniho = -1;
//		sez->delka = 0;
//	} else {
//		Tprvek * aktual = sez->aktualni;
//		Tprvek * pomDalsi = aktual->dalsi;
//		aktual->dalsi = aktual->dalsi->dalsi;
//		aktual->dalsi->pred = aktual;
//	}
//	return true;
//}


bool seznamRemove(Tseznam* sez, float* x) {
	if(isEmpty(sez)) {
		printf("Neni co vymazat\n");
		return false;
	}
	*x = sez->aktualni->hodnota;

	if(sez->aktualni == sez->zacatek) {
		sez->zacatek = NULL;
		sez->aktualni = NULL;
		sez->indexAktualniho = -1;
		sez->delka = 0;
	} else {
		Tprvek * aktual = sez->aktualni;
		aktual->pred->dalsi = aktual->dalsi;
		aktual->dalsi->pred = aktual->pred;
		sez->aktualni = aktual->pred;
		free(aktual);
	}
	return true;
}


bool current(Tseznam* sez, float * data) {
	if(isEmpty(sez)) {
		printf("Neni co posunout\n");
		return false;
	}

	*data = sez->aktualni->hodnota;
	return true;
}


bool next(Tseznam* sez) {
	if(isEmpty(sez)) {
		printf("Neni co posunout\n");
		return false;
	}
	sez->aktualni = sez->aktualni->dalsi;
	return true;
}


bool prev(Tseznam* sez) {
	if(isEmpty(sez)) {
		printf("Neni co posunout\n");
		return false;
	}
	sez->aktualni = sez->aktualni->pred;
	return true;
}

void seznamVypis(Tseznam* sez) {
	if(isEmpty(sez)) {
		printf("Neni co vypsat\n");
		return;
	}
	Tprvek * pom = sez->zacatek;

	do {
		printf("%g\n", pom->hodnota);
		pom = pom->dalsi;
	} while(pom != sez->zacatek);

}

//Tfronta* frInitD(int maxDelka){
//	Tfronta* z = malloc(sizeof(Tfronta));
//	if(z == NULL) {
//		return NULL;
//	}
//	z->prvni= NULL;
//	z->posledni= NULL;
//	z->delka = 0;
//	z->maxDelka = maxDelka;
//	return z;
//}
//
//Tprvek* prvekNovy(float hodnota) {
//	Tprvek* novy=malloc(sizeof(Tprvek));
//	if (novy != NULL) {
//		novy->hodnota = hodnota;
//		novy->dalsi = NULL;
//	}
//	return novy;
//}
//
//bool frDequeue(Tfronta * fronta, float * hodnota) {
//	if(fronta->prvni == NULL && fronta->posledni == NULL) {
//		return false;
//	}else {
//		*hodnota = fronta->prvni->hodnota;
//		Tprvek * pom = fronta->prvni;
//		fronta->prvni = fronta->prvni->dalsi;
//		free(pom);
//		if(fronta->prvni == NULL) {
//			fronta->posledni = NULL;
//		}
//		fronta->delka--;
//		return true;
//	}
//}
//
//void frEnqueue(Tfronta * fronta, float hodnota) {
//	Tprvek* novy = prvekNovy(hodnota);
//	if(novy == NULL) {
//		return NULL;
//	}
//
//	if(fronta->delka >= fronta->maxDelka) {
//		float pom;
//		frDequeue(fronta, &pom);
////		printf("odebrat posledni\n");
//	}
//
//	if(fronta->prvni == NULL && fronta->posledni == NULL) {
//		fronta->prvni = novy;
//		fronta->posledni = novy;
//		fronta->delka++;
//	}else {
//		fronta->posledni->dalsi = novy;
//		fronta->posledni = novy;
//		fronta->delka++;
//	}
//
//}
//
//void frVypis(Tfronta * fronta) {
//	Tprvek * prvek = fronta->prvni;
//
//	while (prvek != NULL) {
//		printf("%g\n", prvek->hodnota);
//		prvek = prvek->dalsi;
//	}
//}
//
//
//void frZrus(Tfronta * fronta) {
//	float prvek;
//	while(frDequeue(fronta, &prvek)) {;}
//	free(fronta);
//}
//
//void prutokac(FILE * fVstup, int pocetPrvku) {
//	Tfronta * fronta;
//	if((fronta = frInitD(pocetPrvku)) == NULL) {
//		printf("Nepovedla se inicializace\n");
//		return 1;
//	}
//	float cislo;
//	while(fscanf(fVstup, "%f", &cislo)==1) {
//		frEnqueue(fronta, cislo);
//	}
//
//	frVypis(fronta);
//
//	frZrus(fronta);
//}

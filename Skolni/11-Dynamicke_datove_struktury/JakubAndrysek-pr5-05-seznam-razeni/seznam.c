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

Tseznam* seznamInitD(){
	Tseznam * seznam = malloc(sizeof(Tseznam));
	if(seznam != NULL) {
		seznam->zacatek = NULL;
		seznam->konec= NULL;
		seznam->aktualni = NULL;
		seznam->indexAktualniho = -1;
		seznam->delka = 0;
	}
	return seznam;
}

void seznamFree(Tseznam *sez){
	if(sez != NULL) {

	}

}


bool seznamInsert(Tseznam* sez, float hodnota){
	Tprvek * nPrvek;
	if(nPrvek = novyPrvek(hodnota) == NULL) {
		return false;
	}

	if(sez->zacatek==NULL && sez->konec==NULL && sez->aktualni==NULL) {
		sez->zacatek = nPrvek;
		sez->konec = nPrvek;
		sez->aktualni = nPrvek;
	}else {
		nPrvek->pred = sez->aktualni;
		nPrvek->dalsi = sez->aktualni->dalsi;
		sez->aktualni->dalsi->pred = nPrvek;
		sez->aktualni->dalsi = nPrvek;
	}
	return true;
}


bool seznamRemove(Tseznam* ssez, float* x){

}
bool next(Tseznam* sez){

}
bool prev(Tseznam* sez){

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

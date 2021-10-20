#ifndef SEZNAM_H_INCLUDED
#define SEZNAM_H_INCLUDED

#include <stdbool.h> // pro praci s typem bool a konstantami true a false
#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>

typedef struct _prvek Tprvek;

struct _prvek {
	float hodnota;
	Tprvek * dalsi;
	Tprvek * pred; //chozi
};

typedef struct {
//	Tprvek* zacatek;
//	Tprvek* konec;
	Tprvek* aktualni;
	int delka;
	int indexAktualniho;
} Tseznam;

Tseznam* seznamInitD();

void seznamFree(Tseznam *sez);
bool seznamInsert(Tseznam* sez, float x);
bool seznamRemove(Tseznam* sez, float* x);
void seznamVypis()
bool next(Tseznam* sez);
bool prev(Tseznam* sez);

#endif // SEZNAM_H_INCLUDED

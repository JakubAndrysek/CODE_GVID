#ifndef GEM_H_INCLUDED
#define GEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float **prvek;
    int radku, sloupcu;
} Tmatice;


enum eChyby {EOK, EROZMER, ECTENI, EPAMET, ENEZNAMA};

extern int cisloChyby;

char* chyboveHlaseni(int kod); // v mainu


Tmatice* vyrobMatici(int radku, int sloupcu);
void znicMatici(Tmatice* matice);

Tmatice* ctiM(FILE *in);
void tiskM(FILE *out, Tmatice *m);

void vymenRadky(Tmatice* matice, int a, int b);
int maxAbsPivot(Tmatice *m, int r);

Tmatice* soucetM(Tmatice *m1, Tmatice *m2);
Tmatice* soucinM(Tmatice *m1, Tmatice *m2);


#endif // GEM_H_INCLUDED


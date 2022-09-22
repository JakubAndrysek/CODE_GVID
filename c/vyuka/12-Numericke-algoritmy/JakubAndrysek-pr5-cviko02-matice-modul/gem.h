#ifndef GEM_H_INCLUDED
#define GEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float **prvek;
    int radku, sloupcu;
} Tmatice;


Tmatice* vyrobMatici(int radku, int sloupcu);
void znicMatici(Tmatice* matice);

Tmatice* ctiM(FILE *in);
void tiskM(FILE *out, Tmatice *m);

Tmatice* soucetM(Tmatice *m1, Tmatice *m2);
Tmatice* soucinM(Tmatice *m1, Tmatice *m2);


#endif // GEM_H_INCLUDED


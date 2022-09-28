#ifndef GEM_H_INCLUDED
#define GEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    float **prvek;
    int radku, sloupcu;
} Tmatice;


enum eChyby {EOK, EROZMER, ECTENI, EPAMET, ENEZNAMA};
enum eReseni {EJEDNO, ENEKONECNO, EZADNE, ECHYBARESENI};

extern int cisloChyby;

const char* chyboveHlaseni(int kod);
const char* reseniRovnice(int kodReseni);

Tmatice* vyrobMatici(int radku, int sloupcu);
void znicMatici(Tmatice* matice);

Tmatice* ctiM(FILE *in);
void tiskM(FILE *out, Tmatice *m);

void vymenRadky(Tmatice* matice, int a, int b);
int maxAbsPivot(Tmatice *m, int r);

void radkoveUpravy(Tmatice* matice, int r);

bool jeHorni(Tmatice* matice);
int testResitelnosti(Tmatice* matice);

Tmatice* soucetM(Tmatice *m1, Tmatice *m2);
Tmatice* soucinM(Tmatice *m1, Tmatice *m2);


#endif // GEM_H_INCLUDED


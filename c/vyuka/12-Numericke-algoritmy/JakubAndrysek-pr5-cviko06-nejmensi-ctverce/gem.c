//
// Created by Jakub Andrýsek on 05.03.2023.
//

#include <math.h>
#include "gem.h"

/** \brief Provede přímý chod GEM
 *
 * \param m Tmatice* Ukazatel na alokovanou matici.
 * \return int Vrací kód chyby.
 */
int gemPrimy(Tmatice *matice) {
    for (int r = 0; r < matice->radku; r++) {
        int k = maxAbsPivot(matice, r);
        if (k != r) {
            maticeVymenRadky(matice, r, k);
        }
        maticeRadkoveUpravy(matice, r);
    }
}

/** \brief Provede zpětný chod GEM.
 *
 * Hodnoty neznámých nastaví do posledního sloupce rozšířené matice soustavy.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 */
void gemZpetny(Tmatice *m) {
    printf("Funkce gemZpetny");

    int posledniSloupec = m->radku;
    for (int r = m->radku - 1; r >= 0; r--) {
        float sum = 0.0f;
        for (int s = r + 1; s < posledniSloupec; s++) {
            sum += m->prvek[r][s] * m->prvek[s][posledniSloupec];
            m->prvek[r][s] = 0.0f;
        }
        float b = m->prvek[r][posledniSloupec];
        float res = (b - sum);
        float div = res / m->prvek[r][r];

        m->prvek[r][r] = 1.0f;
        m->prvek[r][posledniSloupec] = div;

//        maticeTiskni(m);
    }
}


/** \brief Tiskne řešení soustavy rovnic, které je uloženo v posledním sloupci rozšířené matice soustavy.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 */
void gemTiskReseni(Tmatice *m) {
    printf("Reseni soustavy rovnic:\n");
    for(int r = 0; r < m->radku; r++) {
        printf("x%d = %2g\n", r, m->prvek[r][m->radku]);
    }
}

void gemTiskReseniFunkce(float a, float b) {
    if(fabs(a) <= 0.01) {
        printf("f(x)=%2.2g", b);
        return;
    }

    printf("f(x)=%2.2gx%2.2g", a, b);
}
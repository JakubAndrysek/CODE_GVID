/* Modul pro práci s maticemi.
 *
 * Copyright (c) David Martinek, 2018--2022
 */

#include "matice.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


/** \brief Vytvoří matici zadaných rozměrů.*/
Tmatice *maticeAlokuj(int radku, int sloupcu) {
    if (radku >= 0 && radku <= MATICE_MAX_VELIKOST &&
        sloupcu >= 0 && sloupcu <= MATICE_MAX_VELIKOST) {
        // Tady se dynamicky alokuje jen struktura typu Tmatice.
        // Samotné pole uvnitř má v této implementaci pevné rozměry, přičemž
        // my z něj využijeme jen část odpovídající rozměrům radku a sloupcu.
        // Skutečně dynamická 2D matice se dělá jinak.
        Tmatice *m = malloc(sizeof(Tmatice));
        if (m == NULL)
            return NULL;

        m->radku = radku;
        m->sloupcu = sloupcu;

        return m;
    } else {
        return NULL;
    }
}

/** \brief Zruší zadanou matici.*/
void maticeUvolni(Tmatice *matice) {
    free(matice);
    // Takto jednoduše to jde jen v naší primitivní implementaci. Skutečné
    // 2D dynamické pole by se muselo rušit postupně po řádcích.
}

/** \brief Inicializuje všechny prvky matice počáteční hodnotou.*/
void maticeNastavPrvky(Tmatice *matice, float initValue) {
    for (int r = 0; r < matice->radku; ++r) {
        for (int s = 0; s < matice->sloupcu; ++s) {
            matice->prvek[r][s] = initValue;
        }
    }
}

/** \brief Inicializuje všechny prvky matice náhodnými hodnotami. */
void maticeRandom(Tmatice *matice) {
    for (int r = 0; r < matice->radku; ++r) {
        for (int s = 0; s < matice->sloupcu; ++s) {
            {
                matice->prvek[r][s] = (float) ((rand() % 2000) - 1000) / 100;
            }
        }
    }
}


/** \brief Vytiskne matici na obrazovku.*/
void maticeTiskni(const Tmatice *matice) {
    maticeTiskniSoubor(stdout, matice);
}

/** \brief Vytiskne matici do souboru.*/
void maticeTiskniSoubor(FILE *file, const Tmatice *matice) {
    fprintf(file, "%u %u\n", matice->radku, matice->sloupcu);
    printf(ANSI_COLOR_YELLOW"   |");
    for(int s = 0; s < matice->sloupcu; s++) {
        fprintf(file, ANSI_COLOR_YELLOW "%6d   |", s);
    }
    printf("\n");

    for (int r = 0; r < matice->radku; ++r) {
        fprintf(file, ANSI_COLOR_YELLOW "%2d |", r);
        for (int s = 0; s < matice->sloupcu; ++s) {
            float toShow = matice->prvek[r][s];
            if(file != stdout) {
                fprintf(file, " %7.2f ", toShow);
            } else {
                if(toShow == 1) {
                    fprintf(file, ANSI_COLOR_MAGENTA " %7.2f " ANSI_COLOR_YELLOW "|" ANSI_COLOR_RESET, toShow);
                } else if(toShow < 0) {
                    fprintf(file, ANSI_COLOR_BLUE " %7.2f "ANSI_COLOR_YELLOW "|" ANSI_COLOR_RESET, toShow);
                } else if(toShow > 0) {
                    fprintf(file, ANSI_COLOR_GREEN " %7.2f " ANSI_COLOR_YELLOW "|" ANSI_COLOR_RESET, toShow);
                } else {
                    fprintf(file, ANSI_COLOR_RED " %7.2f "ANSI_COLOR_YELLOW "|" ANSI_COLOR_RESET, toShow);
                }
            }
        }
        fprintf(file, "\n");
    }

//    printf(ANSI_COLOR_YELLOW"   |");
//    for(int s = 0; s < matice->sloupcu; s++) {
//        fprintf(file, ANSI_COLOR_YELLOW "%6d   |", s);
//    }
//    fprintf(file, ANSI_COLOR_RESET"\n");

}

/** \brief Vytvoří a přečte matici ze standardního vstupu (klávesnice).*/
Tmatice *maticeCtiZeVstupu(int *chyba) {
    return maticeCtiZeSouboru(stdin, chyba);
}

/** \brief Vytvoří a přečte matici ze souboru.*/
Tmatice *maticeCtiZeSouboru(FILE *file, int *chyba) {
    int radku, sloupcu;
    int ecode = fscanf(file, "%d %d", &radku, &sloupcu);
    if (ecode != 2) {
        *chyba = EMREAD;
        return NULL;
    }

    Tmatice *matice = maticeAlokuj(radku, sloupcu);
    if (matice == NULL) {
        *chyba = EMCREATE;
        return NULL;
    }

    matice->radku = radku;
    matice->sloupcu = sloupcu;

    for (int r = 0; r < matice->radku; ++r) {
        for (int s = 0; s < matice->sloupcu; ++s) {
            ecode = fscanf(file, "%f ", &matice->prvek[r][s]);
            if (ecode != 1) {
                maticeUvolni(matice);
                *chyba = EMREAD;
                return NULL;
            }
        }
    }

    *chyba = EMOK;
    return matice;
}

/** \brief Vymění v matici řádky zadané pomocí indexů.*/
void maticeVymenRadky(Tmatice *m, int r1, int r2) {
//    if (r1 == r2 || r1 * r2 <= 0 || r1 >= m->radku || r2 >= m->radku) {
//        printf("Nesedni radky\n");
//        return;
//    }


    for (int s = 0; s < m->sloupcu; ++s) {
        float pom = m->prvek[r1][s];
        m->prvek[r1][s] = m->prvek[r2][s];
        m->prvek[r2][s] = pom;
    }
}

int maxAbsPivot(Tmatice *matice, int d) {
    int max = d;
    for (int r = 1; r < matice->radku; r++) {
        if (fabsf(matice->prvek[r][d]) > matice->prvek[max][d]) {
            max = r;
        }
    }
    return max;
}

void maticeRadkoveUpravy(Tmatice *matice, int r) {
    for (int k = r + 1; k <= matice->radku - 1; k++) {
        float c = matice->prvek[k][r] / matice->prvek[r][r];
        matice->prvek[k][r] = 0.0f;
        for (int s = r + 1; s <= matice->radku; s++) {
            matice->prvek[k][s] = c * matice->prvek[r][s] - matice->prvek[k][s];
//            printf("rad set [%d][%d]\n", k, s);
//            tiskM(stdout, matice);
        }
    }
}


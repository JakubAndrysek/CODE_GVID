/*
 * Projekt: pr5-cviko01-matice
 * Autor: Jakub Andrysek
 * Datum: 11. 9. 2022
 */

//#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

#define MAXN 100


typedef struct {
    float prvek[MAXN][MAXN];
    int radku, sloupcu;
} Tmatice;


void ctiM(FILE *in, Tmatice *m) {
    if (fscanf(in, "%d", &m->radku) != 1) {
        printf("E: nenacteny rozmery matice - radky\n");
        exit(EXIT_FAILURE);
    }

    if (fscanf(in, "%d ", &m->sloupcu) != 1) {
        printf("E: nenacteny rozmery matice - sloupce\n");
        exit(EXIT_FAILURE);
    }

    for (int r = 0; r < (m->radku); r++) {
        for (int s = 0; s < (m->sloupcu); s++) {
            if (!fscanf(in, "%f ", &m->prvek[r][s]) == 1) {
                printf("E: cteni matice r:%d s:%d\n", r, s);
                m->sloupcu = s;
                m->radku = r;
                exit(EXIT_FAILURE);
            }
        }
    }

    printf("Nactena matice %d x %d\n", m->radku, m->sloupcu);
}

void tiskM(FILE *out, Tmatice *m) {
    for (int r = 0; r < m->radku; r++) {
        for (int s = 0; s < m->sloupcu; s++) {
            printf("%+2.2f | ", m->prvek[r][s]);
        }
        printf("\n");
    }
}

void soucetM(Tmatice *m1, Tmatice *m2, Tmatice *soucet) {
    if (!(m1->radku == m2->radku && m1->sloupcu == m2->sloupcu)) {
        printf("E: matice nelze secist\n");
        exit(EXIT_FAILURE);
    }


    for (int r = 0; r < m1->radku; r++) {
        for (int s = 0; s < m1->sloupcu; s++) {
            soucet->prvek[r][s] = m1->prvek[r][s] + m2->prvek[r][s];
        }
    }

    soucet->radku = m1->radku;
    soucet->sloupcu = m1->sloupcu;
}

void soucinM(Tmatice *m1, Tmatice *m2, Tmatice *soucin) {
    if (m1->sloupcu != m2->radku) {
        printf("E: nelze nasobit matice s rozdilnymi rozmery\n");
        exit(EXIT_FAILURE);
    }

    for (int r = 0; r < m1->radku; r++) {
        for (int s = 0; s < m2->sloupcu; s++) {
            soucin->prvek[r][s] = 0;
            for (int i = 0; i < m1->sloupcu; i++) {
                soucin->prvek[r][s] += m1->prvek[r][i] * m2->prvek[i][s];
            }
        }
    }

    soucin->radku = m1->radku;
    soucin->sloupcu = m2->sloupcu;
}



void nactiDveMatice(char nazevSouboruA[], char nazevSouboruB[], Tmatice *maticeA, Tmatice *maticeB) {
    FILE *fileA = fopen(nazevSouboruA, "r");
    FILE *fileB = fopen(nazevSouboruB, "r");

    if (fileA == NULL || fileB == NULL) {
        printf("E: nepodaril se otevrit soubory\n");
        exit(EXIT_FAILURE);
    }

    ctiM(fileA, maticeA);
    ctiM(fileB, maticeB);
}

void tiskniDveMatice(Tmatice *maticeA, Tmatice *maticeB) {
    printf("Matice A:\n");
    tiskM(stdout, maticeA);

    printf("Matice B:\n");
    tiskM(stdout, maticeB);
}

void nactiNazevSouboru(char nazevSouboru[]) {
    printf("Zadej nazev souboru: ");
    scanf("%19s", nazevSouboru);
}

int testSoucet() {
    printf("Test soucet\n");

    char nazevSouboruA[] = "matSoucetA.txt";
//    nactiNazevSouboru(&nazevSouboruA);

    char nazevSouboruB[] = "matSoucetB.txt";
//    nactiNazevSouboru(&nazevSouboruB);

    Tmatice maticeA;
    Tmatice maticeB;

    nactiDveMatice(nazevSouboruA, nazevSouboruB, &maticeA, &maticeB);
    tiskniDveMatice(&maticeA, &maticeB);

    Tmatice maticeSoucetAB;
    soucetM(&maticeA, &maticeB, &maticeSoucetAB);

    printf("Matice SOUCET:\n");
    tiskM(stdout, &maticeSoucetAB);
    printf("\n\n");
}


void testSoucin() {
    printf("Test soucin\n");

    char nazevSouboruA[] = "matSoucinA.txt";
//    nactiNazevSouboru(&nazevSouboruA);

    char nazevSouboruB[] = "matSoucinB.txt";
//    nactiNazevSouboru(&nazevSouboruB);

    Tmatice maticeA;
    Tmatice maticeB;

    nactiDveMatice(nazevSouboruA, nazevSouboruB, &maticeA, &maticeB);
    tiskniDveMatice(&maticeA, &maticeB);

    Tmatice maticeSoucinAB;
    soucinM(&maticeA, &maticeB, &maticeSoucinAB);

    printf("Matice SOUCIN:\n");
    tiskM(stdout, &maticeSoucinAB);
    printf("\n\n");
}

int main(int argc, char *argv[])  // pro parametry prikazoveho radku
{
    testSoucet();
    testSoucin();

    return 0;
}

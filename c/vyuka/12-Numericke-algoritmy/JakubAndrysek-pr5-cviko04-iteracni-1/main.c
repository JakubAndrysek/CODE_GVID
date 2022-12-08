/* Téma matice a moduly - varianta s polem pevných rozměrů
 *
 * Copyright (c) David Martinek, 2018--2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <time.h>

#include "gvid.h"
#include "matice.h"


/** \brief Otestuje operace #maticeAlokuj, #maticeRandom a #maticeTiskni.
 *
 * Tady si prohlédni, jak se s maticí zachází, tj. jak se vytváří a jak se
 * předává do podprogramů. Ve svých operacích to dělej podobně.
 */
void testInit(void) {
    printf("==========================================\n");
    printf("Test vytvoreni a inicializace matice\n");
    Tmatice *matice = maticeAlokuj(5, 3);
    if (matice == NULL) {
        printf("Matici se nepovedlo alokovat.\n");
        return;
    }

//  maticeNastavPrvky(matice, 1.2f);

    maticeRandom(matice);
    maticeTiskni(matice);

    maticeUvolni(matice);

    printf("==========================================\n");
}


/** \brief Otestuje funkce pro čtení ze a zápis do souboru.
 *
 * \param input char*   Jméno vstupního souboru nebo NULL
 * \param output char*  Jméno výstupního souboru nebo NULL
 * \return int Vrací EXIT_FAILURE v případě chyby při práci se soubory.
 *
 * <p>Pokud je místo jména vstupního nebo výstupního souboru prázdný ukazatel
 * NULL, použije se soubor stdin nebo stdout.</p>
 *
 */
int testFileRW(char *input, char *output) {
    printf("==========================================\n");
    printf("Test cteni a zapisu ze a do souboru\n");
    FILE *fin = stdin;
    FILE *fout = stdout;

    int exitCode = EXIT_SUCCESS;

    if (input != NULL)
        fin = fopen(input, "r");

    if (output != NULL)
        fout = fopen(output, "w");

    if (fin == NULL) {
        fprintf(stderr, "Chybny nazev vstupniho souboru.");
        fin = stdin;
        input = NULL;
    }

    if (fout == NULL) {
        fprintf(stderr, "Chybny nazev vystupniho souboru.");
        fout = stdout;
        output = NULL;
    }

    int chk;
    Tmatice *m = maticeCtiZeSouboru(fin, &chk);
    if (m != NULL) {
        maticeTiskniSoubor(fout, m);
        maticeUvolni(m);
    } else {
        fprintf(stderr, "Chyba pri cteni vstupniho souboru.");
        exitCode = EXIT_FAILURE;
    }


    if (input != NULL) fclose(fin);
    if (output != NULL) fclose(fout);
    printf("==========================================\n");
    return exitCode;
}


/** \brief Vynásobí dvě matice a výsledek uloží do třetí nové matice.
 *
 * \param a const Tmatice* První vstupní matice.
 * \param b const Tmatice* Druhá vstupní matice.
 * \param c Tmatice* Výsledná, zatím nevytvořená matice.
 * \return bool Vrací true, pokud se operace povedla, jinak false.
 *
 * <p>Parametr c musí ukazovat na prozatím nevytvořenou matici, jinak dojde ke
 * ztrátě dat.</p>
 *
 * <p>Pokud jsou vstupní matice kompatibilní, tj. a->sloupcu == b->radku, dojde
 * k vytvoření výsledné matice o rozměrech c->radku = a-radku a c->sloupcu = b->sloupcu.
 * Do této matice pak bude uložen výsledek násobení a*b v tomto pořadí.</p>
 *
 * <p>Pozor! Operace maticového násobení není komutativní, tudíž záleží na
 * pořadí operandů.</p>
 */
Tmatice *maticeMult(const Tmatice *a, const Tmatice *b) {
    if (a->sloupcu != b->radku)
        return NULL;

    Tmatice *c = maticeAlokuj(a->radku, b->sloupcu);
    if (c == NULL)
        return NULL;

    for (int row = 0; row < c->radku; ++row) {
        for (int col = 0; col < c->sloupcu; ++col) {
            double ssum;
            ssum = 0.0;
            for (int k = 0; k < a->sloupcu; ++k) {
                ssum += a->prvek[row][k] * b->prvek[k][col];
            }
            c->prvek[row][col] = ssum;
        }
    }
    return c;

//  Poznámka: Všimni si, že operace se sama stará o alokaci výsledku a ošetření
//  chyb, které to může generovat. Jako autor takové operace nemůžu chtít po
//  uživateli (této funkce), aby před samotným spuštěním funkce prováděl nějaké
//  kroky nutné pro správné chování této funkce. Programy, které toto vyžadují,
//  jsou takzvaně "křehké", což je protiklad k programům "robustním".
}

/** \brief Test operací #maticeRandom a #maticeMult. */
void testMult(void) {
    printf("==========================================\n");
    printf("Test nasobeni nahodnych matic\n");
    Tmatice *a = maticeAlokuj(4, 2);
    Tmatice *b = maticeAlokuj(2, 3);

    maticeRandom(a);
    maticeRandom(b);

    maticeTiskni(a);
    printf("*\n");
    maticeTiskni(b);
    printf("=\n");
    Tmatice *c = maticeMult(a, b);
    if (c != NULL) {
        maticeTiskni(c);
        maticeUvolni(c);
    } else
        printf("Tohle nejde!\n");

    maticeUvolni(a);
    maticeUvolni(b);
    printf("==========================================\n");
}





Tmatice* testMaticeNacteni(char *jmenoSouboru) {
    printf("==========================================\n");

    FILE *fin;
    if (jmenoSouboru != NULL) {
        fin = fopen(jmenoSouboru, "r");
    } else {
        printf("Spatne jmeno souboru\n");
        exit(EXIT_FAILURE);
    }


    if (fin == NULL) {
        fprintf(stderr, "Chybny nazev vstupniho souboru.");
        exit(EXIT_FAILURE);
    }


    int chyba;
    Tmatice *matice = maticeCtiZeSouboru(fin, &chyba);
    if (chyba != EMOK) {
        printf("Chyba...");
        exit(EXIT_FAILURE);
    }

    maticeTiskni(matice);
    return matice;


    printf("==========================================\n");
}





/** \brief Tiskne řešení soustavy rovnic, které je uloženo v posledním sloupci rozšířené matice soustavy.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 */
void tiskReseni(Tmatice *m) {
    printf("Reseni soustavy rovnic:\n");
    for (int r = 0; r < m->radku; ++r) {
        printf("x%d = %g\n", r, m->prvek[r][m->sloupcu - 1]);
    }
}


bool jeDiagonalneDominanatni(Tmatice *m) {
    int radku = m->radku;
    float sum = 0;
    for(int r = 0; r < radku; r++) {
        for(int s = 0; s < radku; s++) {
            if(r != s) {
                sum += m->prvek[r][s];
            }
        }
        if(sum >= m->prvek[r][r]) {
            return false;
        }
        sum = 0;
    }
    return true;
}

bool jeUpravena(Tmatice *m) {
    if(m->radku != m->sloupcu+1) {
        printf("Spatne rozmery\n");
        return false;
    }
    for(int rs = 0; rs < m->radku; rs++) {
        if(m->prvek[rs][rs] != 0) {
            return false;
        }
    }
    return true;
}

bool jeDDPoUprave(Tmatice *m) {
    float sum = 0;
    for(int r = 0; r < m->radku; r++) {
        for(int s = 0; s < m->radku; s++) {
            if(r != s) {
                sum += m->prvek[r][s];
            }
        }
        if(sum >= 1) {
            return false;
        }
        sum = 0;
    }
    return true;
}


void testDDMatice() {
    printf("testDDMatice\n");

    Tmatice* matice = testMaticeNacteni("jeDDM.txt");
    bool jeDD = jeDiagonalneDominanatni(matice);
    printf("Je DDM: %d (ma byt ano)\n", jeDD);

    Tmatice* maticeNeDD = testMaticeNacteni("neDDM.txt");
    bool jeDD_false = jeDiagonalneDominanatni(maticeNeDD);
    printf("Je DDM: %d (ma byt ne)\n", jeDD_false);
}


void upravaMatice(Tmatice *m) {
    int radku = m->radku;
    for (int r = 0; r < radku; r++) {
        for(int s = 0; s <= radku; s++) {
            if(r != s) {
                m->prvek[r][s] /= m->prvek[r][r];
            }
        }
        m->prvek[r][r] = 0;
    }
}

void testUpravaMatice() {
    Tmatice* matice = testMaticeNacteni("prez.txt");

    upravaMatice(matice);

    maticeTiskni(matice);

    bool jeDD = jeDDPoUprave(matice);
    printf("Je DDM: %d (ma byt ano)\n", jeDD);
}

float vypocetGS(Tmatice* m, Tmatice* x, int r) {
    float sum = 0;
    int radku = m->radku;
    for(int s = 0; s < m->radku; s++) {
        sum += m->prvek[r][s] * x->prvek[s][0];
    }
    float res = m->prvek[r][radku] - sum;
    return res;
}

void resGS(Tmatice *m, float eps, Tmatice *x) {
    bool jePresny = false;

    while(!jePresny) {
        jePresny = true;
        for(int r = 0; r < m->radku; r++) {
            float xPred = x->prvek[r][0];
            x->prvek[r][0] = vypocetGS(m, x, r);
            jePresny = jePresny && (fabsf(xPred - x->prvek[r][0]) < eps);
        }
//        maticeTiskni(x);
    }
}


void testGS(void) {
    printf("testGS\n");

    Tmatice* matice = testMaticeNacteni("prez.txt");

    bool jeDD = jeDiagonalneDominanatni(matice);
    if(!jeDD) {
        printf("Neni DD\n");
        return;
    }

    upravaMatice(matice);
//    maticeTiskni(matice);

    Tmatice* x = maticeAlokuj(matice->radku, 1);
    maticeNastavPrvky(x, 0);
//    maticeTiskni(x);

    resGS(matice, 0.01f, x);
    maticeTiskni(x);
}


void resJacobi(Tmatice *m, float eps, Tmatice *x) {
    bool jePresny = false;
    Tmatice* y = maticeAlokuj(m->radku, 1);

    while(!jePresny) {
        jePresny = true;
        for(int r = 0; r < m->radku; r++) {
            y->prvek[r][0] = vypocetGS(m, x, r);
            jePresny = jePresny && (fabsf(y->prvek[r][0] - x->prvek[r][0]) < eps);
        }
        Tmatice* pom = x;
        x = y;
        y = pom;
//        maticeTiskni(x);
    }
}

void testJacobi(void) {
    printf("testJacobi\n");
    Tmatice* matice = testMaticeNacteni("prez.txt");

    bool jeDD = jeDiagonalneDominanatni(matice);
    if(!jeDD) {
        printf("Neni DD\n");
        return;
    }

    upravaMatice(matice);
//    maticeTiskni(matice);

    Tmatice* x = maticeAlokuj(matice->radku, 1);
    maticeNastavPrvky(x, 0);
//    maticeTiskni(x);

    resJacobi(matice, 0.01f, x);
    maticeTiskni(x);
}

/** \brief Startovní bod programu.
 *
 * \return int Návratový kód programu.
 */
int main(void) {
    srand(time(NULL));

    enableColors();

//  testInit();
//  testFileRW("A.txt", NULL); // NULL -> bude zapisovat na stdout
//  testMult();
//  testMatice("C.txt");     // otestuj i jiné soubory

//    testDDMatice();

//    testUpravaMatice();

    testGS();
    testJacobi();

    return EXIT_SUCCESS;
}

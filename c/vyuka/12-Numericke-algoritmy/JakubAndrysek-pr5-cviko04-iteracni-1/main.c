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
        return;
    }


    if (fin == NULL) {
        fprintf(stderr, "Chybny nazev vstupniho souboru.");
        return;
    }


    int chyba;
    Tmatice *matice = maticeCtiZeSouboru(fin, &chyba);
    if (chyba != EMOK) {
        printf("Chyba...");
        return;
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
    for()
}


void testDDMatice() {
    printf("testDDMatice\n");

    Tmatice* matice = testMaticeNacteni("prez.txt")
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



    return EXIT_SUCCESS;
}

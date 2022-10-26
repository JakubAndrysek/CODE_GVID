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



/** \brief Vrací true, když je zadaná matice ve tvaru pro provedení přímého chodu GEM.
 *
 * Součástí testu jsou i správné rozměry.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 * \return bool Vrací hodnotu true, když matice je rozšířenou maticí soustavy
 *              ve tvaru po provedení přímého chodu Gaussovy eliminační metody
 *              a soustava je dále řešitelná. Jinak vrací hodnotu false.
 */
bool gemPoPrimem(Tmatice *m) {
    for (int r = 1; r <= m->radku - 1; r++) {
        for (int s = 0; s < r; s++) {
            if (m->prvek[r][s] != 0) {
                return false;
            }
        }
    }

    for (int r = 0; r < m->radku; r++) {
        if (m->prvek[r][r] == 0) {
            return false;
        }
    }

    return true;
}

/** \brief Vrací true, když je zadaná matice ve tvaru pro provedení přímého chodu GJEM.
 *
 * Součástí testu jsou i správné rozměry.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 * \return bool Vrací hodnotu true, když matice je rozšířenou maticí soustavy
 *              ve tvaru po provedení přímého chodu Gauss-Jordanovy eliminační metody
 *              a soustava je dále řešitelná. Jinak vrací false.
 */
bool gjemPoPrimem(Tmatice *m) {
    // TODO: naprogramuj ji
    return false;
}


int zjistiReseni(Tmatice *m) {
    int rad = m->radku - 1;
    if (m->prvek[rad][rad] != 0) {
        printf("Jedno reseni\n");
        return 1;
    } else if (m->prvek[rad][rad + 1] == 0) {
        printf("Nekonecno\n");
        return -1;
    } else {
        printf("Nema reseni");
        return 0;
    }
}


/** \brief Test matic po přímém chodu
 *
 * Zadání:
 * Pro řešení využij funkce z modulu matice.h a funkce gemPoPrimem a gjemPoPrimem.
 * 1. Načti soubor s maticí (nebo si ji inicializuj přímo tady ve funkci).
 * 2. Otestuj ji a vytiskni, zda jde o matici po provedení přímého chodu GEM nebo GJEM.
 * 3. Vypiš, kolik řešení zadaná soustava má (0, 1, nekonečno).
 */
void testMatice(char *jmenoSouboru) {
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

    bool jePoPrimem = gemPoPrimem(matice);
    if (jePoPrimem) {
        printf("Je po primem\n");
    } else {
        printf("Neni po primem\n");
    }

    int reseni = zjistiReseni(matice);
    printf("Pocet reseni %d\n", reseni);


    printf("==========================================\n");
}

// Začni testováním a zpětnými chody. Tohle dodělej pak.
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


/** \brief Provede přímý chod GJEM
 *
 * \param m Tmatice* Ukazatel na alokovanou matici.
 * \return int Vrací kód chyby.
 *
 */
int gjemPrimy(Tmatice *m) {
    printf("==========================================\n");
    printf("Primy chod GJEM\n");

    for (int r = 0; r < m->radku; r++) {
        for (int k = 0; k < m->radku; k++) {
            if (k != r) {
                float c = m->prvek[k][r] / m->prvek[r][r];
                m->prvek[k][r] = 0.0f;
                for (int s = r + 1; s <= m->radku; s++) {
                    m->prvek[k][s] = c * m->prvek[r][s] - m->prvek[k][s];
//            printf("rad set [%d][%d]\n", k, s);
//            tiskM(stdout, matice);
                }
            }

        }
    }

}

void testPrimyChod(char *jmenoSouboru) {
    printf("==========================================\n");
    printf("Primy chod GEM\n");

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

    gemPrimy(matice);
    maticeTiskni(matice);

    printf("==========================================\n");
}

void testPrimyChodGjem(char *jmenoSouboru) {
    printf("==========================================\n");
    printf("Primy chod GJEM\n");

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

    gjemPrimy(matice);
    maticeTiskni(matice);

    printf("==========================================\n");
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

        maticeTiskni(m);
    }
}

/** \brief Provede zpětný chod GJEM.
 *
 * Hodnoty neznámých nastaví do posledního sloupce rozšířené matice soustavy.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 */
void gjemZpetny(Tmatice *m) {
    printf("Funkce gjemZpetny");
    int radku = m->radku;
    for(int r = 0; r < m->radku; r++) {
        m->prvek[r][radku] = m->prvek[r][radku] / m->prvek[r][r];
        m->prvek[r][r] = 1;
    }
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

/** \brief Vyřeší upravenou soustavu rovnic.
 *
 * Zadání:
 * Pro řešení využij funkce z modulu matice.h a funkce gemPoPrimem, gjemPoPrimem, gemZpetny a gjemZpetny.
 * 1. Načti soubor s maticí (nebo si ji inicializuj přímo tady ve funkci).
 * 2. Otestuj zda jde o matici s jedním řešením po provedení přímého chodu GEM nebo GJEM.
 * 3. Vyřeš ji.
 * 4. Vypiš řešení soustavy pomocí funkce tiskReseni.
 */
void testZpetnyChod(char *jmenoSouboru) {
    printf("==========================================\n");
    printf("Funkce testZpetnyChod\n");

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

    gemPrimy(matice);
    maticeTiskni(matice);

    gemZpetny(matice);

    tiskReseni(matice);

    printf("==========================================\n");
}


void testZpetnyChodGjem(char *jmenoSouboru) {
    printf("==========================================\n");
    printf("Funkce testZpetnyChod\n");

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

    gjemPrimy(matice);
    maticeTiskni(matice);

    gjemZpetny(matice);

    maticeTiskni(matice);
    tiskReseni(matice);

    printf("==========================================\n");
}


/** \brief Startovní bod programu.
 *
 * \return int Návratový kód programu.
 */
int main(void) {
    srand(time(NULL));

//  testInit();
//  testFileRW("A.txt", NULL); // NULL -> bude zapisovat na stdout
//  testMult();
//  testMatice("C.txt");     // otestuj i jiné soubory
//    testPrimyChod("prezGem.txt"); // prezGem.txt

//    testPrimyChod("prezGem.txt"); // prezGem.txt
//    testPrimyChodGjem("prezGem.txt"); // prezGem.txt

    testZpetnyChod("prezGem.txt"); // otestuj i jiné soubory
//    testZpetnyChod("F.txt"); // otestuj i jiné soubory

//    testZpetnyChodGjem("prezGem.txt"); // otestuj i jiné soubory
//    testZpetnyChodGjem("F.txt"); // otestuj i jiné soubory
    return EXIT_SUCCESS;
}

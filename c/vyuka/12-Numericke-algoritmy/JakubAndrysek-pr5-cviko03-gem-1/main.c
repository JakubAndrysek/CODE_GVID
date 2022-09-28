/*
 * Projekt:
 * Autor:
 * Datum:
 */

//#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
 #include <string.h>  // pro praci s textovymi retezci
 #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
#include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem
#include "gem.h"

//na dialonale neni nula
//pod musi byt nula
//return true bude posledni -> po chybe vyskocim
//kontrola rozmeru neni nulovy


Tmatice* nactiMaticiZeSouboru(char nazevSouboru[]) {
    FILE *file = fopen(nazevSouboru, "r");

    if (file == NULL) {
        printf("E: nepodaril se otevrit soubor %s\n", nazevSouboru);
        exit(EXIT_FAILURE);
    }

    Tmatice* matice = ctiM(file);
    return matice;
}

void nactiNazevSouboru(char nazevSouboru[]) {
    printf("Zadej nazev souboru: ");
    scanf("%19s", nazevSouboru);
}


bool testNacteniAVymena() {
    printf("Test testNacteniAVymena\n");

    char nazevSouboruA[] = "testGem.txt";
//    nactiNazevSouboru(&nazevSouboruA);

    Tmatice *maticeA = nactiMaticiZeSouboru(nazevSouboruA);
    if(maticeA == NULL) {
        printf("Chyba: %s", chyboveHlaseni(cisloChyby));
    }

    tiskM(stdout, maticeA);

    vymenRadky(maticeA, 0, 2);

    printf("Vymen radky:\n");
    tiskM(stdout, maticeA);
}

int gemPrimy(Tmatice *matice) {
    tiskM(stdout, matice);
    printf("\n");

    for(int r = 0; r < matice->radku; r++) {
        int k = maxAbsPivot(matice, r);
        if(matice->prvek[k][r] == 0) {
            printf("Chyba reseni primeho chodu\n");
            return EXIT_FAILURE;
        }

        if(r!=k) {
            printf("Pred vymenou %d\n", r);
            tiskM(stdout, matice);

            printf("Po vymene %d\n", r);
            vymenRadky(matice, r, k);
            tiskM(stdout, matice);

            printf("Po radkoveUpravy %d\n", r);
            radkoveUpravy(matice, r);
            tiskM(stdout, matice);

            printf("\n");
        }
    }

    return jeHorni(matice);
}

int gem() {
    char nazevSouboruA[] = "prezGem.txt";

    Tmatice *matice = nactiMaticiZeSouboru(nazevSouboruA);
    if(matice == NULL) {
        printf("Chyba (nactiMaticiZeSouboru): %s", chyboveHlaseni(cisloChyby));
        return EXIT_FAILURE;
    }

    if(gemPrimy(matice) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    int reseni = testResitelnosti(matice);
    if(reseni != EJEDNO) {
        printf("Chyba (testResitelnosti): %s", reseniRovnice(reseni));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


int main(int argc, char *argv[])  // pro parametry prikazoveho radku
{
    int gemResult = gem();
    return gemResult;
}

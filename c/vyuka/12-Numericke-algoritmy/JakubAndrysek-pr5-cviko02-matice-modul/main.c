/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
 #include <string.h>  // pro praci s textovymi retezci
 #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
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

    if (file == NULL || file == NULL) {
        printf("E: nepodaril se otevrit soubor %s\n", nazevSouboru);
        exit(EXIT_FAILURE);
    }

    Tmatice* matice = ctiM(file);
    return matice;
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

bool testSoucet() {
    printf("Test soucet\n");

    char nazevSouboruA[] = "matSoucetA.txt";
//    nactiNazevSouboru(&nazevSouboruA);

    char nazevSouboruB[] = "matSoucetB.txt";
//    nactiNazevSouboru(&nazevSouboruB);

    Tmatice *maticeA = nactiMaticiZeSouboru(nazevSouboruA);
    Tmatice *maticeB = nactiMaticiZeSouboru(nazevSouboruB);
    tiskniDveMatice(maticeA, maticeB);

    Tmatice *maticeSoucetAB = soucetM(maticeA, maticeB);

    printf("Matice SOUCET:\n");
    tiskM(stdout, maticeSoucetAB);
    printf("\n\n");

    znicMatici(maticeA);
    znicMatici(maticeB);
    znicMatici(maticeSoucetAB);
    return true;
}


bool testSoucin() {
    printf("Test soucin\n");

    char nazevSouboruA[] = "matSoucinA.txt";
//    nactiNazevSouboru(&nazevSouboruA);

    char nazevSouboruB[] = "matSoucinB.txt";
//    nactiNazevSouboru(&nazevSouboruB);

    Tmatice *maticeA = nactiMaticiZeSouboru(nazevSouboruA);
    Tmatice *maticeB = nactiMaticiZeSouboru(nazevSouboruB);
    tiskniDveMatice(maticeA, maticeB);


    Tmatice *maticeSoucinAB = soucinM(maticeA, maticeB);

    if(maticeSoucinAB == NULL) {
      return false;
    }

    printf("Matice SOUCIN:\n");
    tiskM(stdout, maticeSoucinAB);
    printf("\n\n");

    znicMatici(maticeA);
    znicMatici(maticeB);
    znicMatici(maticeSoucinAB);
    return true;
}

int main(int argc, char *argv[])  // pro parametry prikazoveho radku
{
    testSoucet();
    testSoucin();

    return 0;
}

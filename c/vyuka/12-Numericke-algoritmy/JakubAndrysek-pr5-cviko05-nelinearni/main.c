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
#include "nelinearni.h"

void testHorner() {
    const int pocet = 5;
    float koef[pocet] = {2,3,1,-2, 10};

    float vys = horner(koef, pocet, 2);

    printf("Vysledek %g\n", vys);
}


float f1(float x) { // protne v bodech -0.95 a 1.58
    // -5x^2+3.2x^1+7.5
    float koef[] = {-5.0, 3.2, 7.5};
    return horner(koef, 3, x);
}

float f2(float x) { // neprotne se
    // 3x^2+3.2x^1+7.5
    const int n = 3;
    float koef[n] = {3, 3.2, 7.5};
    return horner(koef, n, x);
}

float fNewton(float x) {
    const int n = 4;
    float koef[n] = {6, 4, -7, -2};
    return horner(koef, n, x);
}

float fNewtonDeriv(float x) {
    const int n = 3;
    float koef[n] = {18, 8, -7};
    return horner(koef, n, x);
}


void testBisekce() {
    float koren = bisekce(0.0, 2.0, f1, 0.001);
//    float koren = bisekceRek(0.0, 2.0, f1, 0.001);


    printf("Bisekce %f\n", koren);
}

void testRegulaFalsi() {
    float koren = regulaFalsi(0.0, 2.0, f1, 0.001);

    printf("RegulaFalsi %f\n", koren);
}

void testMetodaSecen() {
    // extrapolacni metoda
    // nemusi konvergovat
    // ukoncit po nejakem case
    // pokud je koren uvnitr intervlu => je to regula falsi
    float koren = secny(0.0, 2.0, f1, 0.001, 1000);
    if(koren == MAXFLOAT) {
        printf("Algoritmus nenasel vysledek, proces byl zastaven\n");
        return;
    }

    printf("MetodaSecen %f\n", koren);
}


void testNewton() {
    // za X dosazujem -1; -0.5; 0.75
    float koren = newton(0, fNewton, fNewtonDeriv, 0.001, 1000);

    if(koren == MAXFLOAT) {
        printf("Algoritmus nenasel vysledek, proces byl zastaven\n");
        return;
    }
    printf("Metoda Newton %f\n", koren);
}

/** \brief Startovní bod programu.
 *
 * \return int Návratový kód programu.
 */
int main(void) {
    srand(time(NULL));

    enableColors();

    testHorner();
    testBisekce();
    testRegulaFalsi();
    testMetodaSecen();
    testNewton();



    return EXIT_SUCCESS;
}

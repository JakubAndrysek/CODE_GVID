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
    printf("Vysledek %f\n", vys);
}


float f1(float x) {
    float koef[] = {-5.0, 3.2, 7.5};
    return horner(koef, 2, x);
}


void testBisekce() {
    float koren = bisekce(0.0, 2.0, f1, 0.001);

    printf("Bisekce %f\n", koren);
}

void testRegulaFalsi() {
    float koren = regulaFalsi(0.0, 2.0, f1, 0.001);

    printf("Bisekce %f\n", koren);
}


/** \brief Startovní bod programu.
 *
 * \return int Návratový kód programu.
 */
int main(void) {
    srand(time(NULL));

    enableColors();

//    testHorner();
//    testBisekce();
    testRegulaFalsi();



    return EXIT_SUCCESS;
}

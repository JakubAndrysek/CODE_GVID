#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include "matice.h"
#include "gem.h"
#include "pole.h"
#include "nejmensiCtverce.h"


void testLinRegresePoleH() {
    ctverceLinearniRegrese(TAB_X, TAB_Y, TAB_LEN);
}

void testLinRegresePoleFile(const char *filename) {
    const int maxLen = 300;
    double x[maxLen];
    double y[maxLen];

    int realLen = ctverceLoadDataFromFile(filename, x, y, maxLen);
    if(realLen <= 0) {
        printf("Error loading line (loaded lines: %d)\n", realLen);
    }

//    printf("Len %d", realLen);

    printf("Konstantni regrese\n");
    ctverceLinearniRegrese(x, y, realLen);

    printf("Linearni regrese\n");
    ctverceKonstantniRegrese(y, realLen);
}

void testLinRegresePoleFileE(){
    testLinRegresePoleFile("E.txt");
}

void testLinRegresePoleFileF(){
    testLinRegresePoleFile("F.txt");
}


/** \brief Startovní bod programu.
 *
 * \return int Návratový kód programu.
 */
int main(void) {
    testLinRegresePoleH();
    testLinRegresePoleFileE();
    testLinRegresePoleFileF();
    return EXIT_SUCCESS;
}

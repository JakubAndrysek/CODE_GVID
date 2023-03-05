//
// Created by Jakub Andrýsek on 05.03.2023.
//

#include "nejmensiCtverce.h"

void linRegreseHelper(const double x[], const double y[], unsigned int n, double *a, double *b) {
    double sumx = 0.0;
    double sumx2 = 0.0;
    double sumy = 0.0;
    double sumxy = 0.0;

    for (int i = 0; i < n; i++) {
        sumx += x[i];
        sumx2 += x[i] * x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
    }

    Tmatice matice = {
            .radku = 2,
            .sloupcu = 3,
            .prvek = {
                    {sumx2, sumx, sumxy},
                    {sumx, n, sumy},
            },
    };

    maticeTiskni(&matice);
    gemPrimy(&matice);
    gemZpetny(&matice);

    maticeTiskni(&matice);
    gemTiskReseni(&matice);

    *a = matice.prvek[0][matice.radku];
    *b = matice.prvek[1][matice.radku];
}

void ctverceLinearniRegrese(const double x[], const double y[], unsigned int n) {
    double a;
    double b;
    linRegreseHelper(x, y, n, &a, &b);
    gemTiskReseniFunkce(a, b);
}

int ctverceLoadDataFromFile(const char *filename, double x[], double y[], const int maxNum) {
    FILE *f = fopen(filename, "r");
    if(f == NULL)  {
        printf("Error loading file\n");
        return -1;
    }

    char ignoreLine[256];
    fgets(ignoreLine, sizeof(ignoreLine), f);
    fgets(ignoreLine, sizeof(ignoreLine), f);

    int index = 0;
    while (fscanf(f, "%lf%lf", &x[index], &y[index]) == 2) {
        index++;
        if(index >= maxNum) {
            printf("x = %g, y = %g\n", &x[index], &y[index]);
            break;
        }
    }
    return index;
}
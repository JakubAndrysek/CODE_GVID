//
// Created by Jakub Andrýsek on 05.03.2023.
//

#ifndef JAKUBANDRYSEK_PR5_CVIKO06_NEJMENSI_CTVERCE_NEJMENSICTVERCE_H
#define JAKUBANDRYSEK_PR5_CVIKO06_NEJMENSI_CTVERCE_NEJMENSICTVERCE_H

#include "gem.h"

void linRegreseHelper(const double x[], const double y[], unsigned int n, double *a, double *b);
void ctverceLinearniRegrese(const double x[], const double y[], unsigned int n);

int ctverceLoadDataFromFile(const char *filename, double x[], double y[], const int maxNum);

void ctverceKonstantniRegrese(const double y[], unsigned int n);
#endif //JAKUBANDRYSEK_PR5_CVIKO06_NEJMENSI_CTVERCE_NEJMENSICTVERCE_H

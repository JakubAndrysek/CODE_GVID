//
// Created by Jakub Andrýsek on 01.12.2022.
//

#ifndef JAKUBANDRYSEK_PR5_CVIKO03_GEM_2_NELINEARNI_H
#define JAKUBANDRYSEK_PR5_CVIKO03_GEM_2_NELINEARNI_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef float (*Tfun)(float);

float horner(const float koef[], int n, float x);

float f1(float x);

float bisekce(float a, float b, Tfun f, float epsilon);
float bisekceRek(float a, float b, Tfun f, float epsilon);

float regulaFalsi(float a, float b, Tfun f, float epsilon);
float secny(float a, float b, Tfun f, float epsilon, int iterationOut);

float newton(float x, Tfun fNewton, Tfun fNewtonDeriv, float epsilon, int iterationOut);


#endif //JAKUBANDRYSEK_PR5_CVIKO03_GEM_2_NELINEARNI_H

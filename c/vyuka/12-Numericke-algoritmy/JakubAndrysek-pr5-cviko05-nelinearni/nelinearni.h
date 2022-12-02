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


#endif //JAKUBANDRYSEK_PR5_CVIKO03_GEM_2_NELINEARNI_H

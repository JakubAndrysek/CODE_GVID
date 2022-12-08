//
// Created by Jakub Andrýsek on 01.12.2022.
//

#include "nelinearni.h"



float horner(const float koef[], int n, float x) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum*=x;
        sum += koef[i];
    }
    return sum;
}


float bisekce(float a, float b, Tfun f, float epsilon) {
    float fa = f(a); // vycisleni f

    float c = (a+b) / 2;
    float fc = f(c);
    while(fabsf(fc) > epsilon) {
        if(fa * fc < 0) {
            b = c;
        } else {
            a = c;
            fa = fc;
        }
        c = (a+b) / 2;
    }
    return c;
}

float regulaFalsiVzorec(float a, float b, float fa, float fb) {
    float c = (b*fa - a*fb) / (fa - fb);
    return c;
}

float regulaFalsi(float a, float b, Tfun f, float epsilon) {
    float fa = f(a);
    float fb = f(b);
    float c = regulaFalsiVzorec(a, b, fa, fb);
    float fc = f(c);
    while (fabsf(fc) >= epsilon) {
        if(fa * fc) {
            b = c;
        } else {
            a = c;
            fa = fc;
        }
        c = regulaFalsiVzorec(a, b, fa, fb);
    }
}
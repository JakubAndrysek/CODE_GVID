//
// Created by Jakub Andrýsek on 01.12.2022.
//

#include "nelinearni.h"


float horner(const float koef[], int n, float x) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum *= x;
        sum += koef[i];
    }
    return sum;
}


float bisekce(float a, float b, Tfun f, float epsilon) {
    float fa = f(a); // vycisleni f

    float c = (a + b) / 2;
    float fc;
    while (fabsf(fc = f(c)) >= epsilon) {
        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
            fa = fc;
        }
        c = (a + b) / 2;
    }
    return c;
}

float bisekceRek(float a, float b, Tfun f, float epsilon) {
    float middle = (a + b) / 2;
    float fmiddle = f(middle);
    if (fabsf(fmiddle) < epsilon) {
        return middle;
    }

    if (f(a) * fmiddle < 0) {
        return bisekce(a, middle, f, epsilon);
    } else {
        return bisekce(middle, b, f, epsilon);
    }
}

float regulaFalsiVzorec(float a, float b, float fa, float fb) {
//    float c = (b*fa - a*fb) / (fa - fb);
    float c = a + fa * (b - a) / (fa - fb);
    return c;
}

float regulaFalsi(float a, float b, Tfun f, float epsilon) {
    float fa = f(a);
    float fb = f(b);
    float c = regulaFalsiVzorec(a, b, fa, fb);
    float fc;
    while (fabsf(fc = f(c)) >= epsilon) {
        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
            fa = fc;
        }
        c = regulaFalsiVzorec(a, b, fa, fb);
    }
    return c;
}


float secnyVzorec(float a, float b, float fa, float fb) {
//    float c = (b*fa - a*fb) / (fa - fb);
//    float c = a + fa*(b-a)/(fa-fb);
//    float c = a - (fa * (a - b) / fa - fb);
//    float c = b  - ((fb * (b - a)) / (fb - fa));
    float c = a + fa * (b - a) / (fa - fb);
    return c;
}

float secny(float a, float b, Tfun f, float epsilon, int iterationOut) {
    float fa = f(a);
    float fb = f(b);
    float fc;
    float c = secnyVzorec(a, b, fa, fb);
    while (fabsf(fc = f(c)) >= epsilon) {
        if (iterationOut < 0) {
            return MAXFLOAT;
        }
        a = b;

        b = c;
        c = secnyVzorec(a, b, f(a), f(b));
        iterationOut--;
    }
    return c;
}


float newtonVzorec(float xPred, Tfun fNewton, Tfun fNewtonDeriv) {
    float xNov = xPred - (fNewton(xPred) / fNewtonDeriv(xPred));
    return xNov;
}

float newton(float x, Tfun fNewton, Tfun fNewtonDeriv, float epsilon, int iterationOut) {
    while (fabsf(fNewton(x)) > epsilon) {
        if (iterationOut < 0) {
            return MAXFLOAT;
        }

        x = newtonVzorec(x, fNewton, fNewtonDeriv);
        iterationOut--;
    }

    return x;
}
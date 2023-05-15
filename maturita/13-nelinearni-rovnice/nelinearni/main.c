#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

typedef float (*Tfun)(float); // zavola se pomoci: Tfun func = f1; a pote func(2.0)

float horner(float arr[], int n, float zaklad) {
	float sum = 0;
	for(int i = 0; i < n; i++) {
		sum *= zaklad;
		sum += arr[i];
	}
	return sum;
}

//
float f1(float x) { // protne v bodech -0.95 a 1.58
    // -5x^2+3.2x^1+7.5
    float koef[] = {-5.0, 3.2, 7.5};
    return horner(koef, 3, x);
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


float puleniIntervaluBisekce(float interA, float interB, Tfun fun, float epsilon) {
	float fInterA = fun(interA); // vycisleni funkce v bode A

	float midd = (interA + interB) / 2.0;
	float fMidd;
	while(fabs(fMidd = fun(midd)) >= epsilon) {
		if(fInterA * fMidd < 0) {
			interB = midd;
		} else {
			interA = midd;
			fInterA = fMidd;
		}
		midd = (interA + interB) / 2.0; // jde i pomoci DO WHILE
	}
	return midd;
}

float vzorecRegulaFalsiSecen(float interA, float interB, float fInterA, float fInterB) {
	return ((interB*fInterA) - (interA*fInterB)) / (fInterA - fInterB);
}

float regulaFalsi(float interA, float interB, Tfun fun, float epsilon) {
	float fInterA = fun(interA); // vycisleni funkce v bode A
	float fInterB = fun(interB); // vycisleni funkce v bode B

	float midd = (interA + interB) / 2.0;
	float fMidd;
	while(fabs(fMidd = fun(midd)) >= epsilon) {
		if(fInterA * fMidd < 0) {
			interB = midd;
		} else {
			interA = midd;
			fInterA = fMidd;
		}
		midd = vzorecRegulaFalsiSecen(interA, interB, fInterA, fInterB); // jde i pomoci DO WHILE
	}
	return midd;
}

// nemusi konvergovat
float secny(float interA, float interB, Tfun fun, float epsilon, int maxIteraci) {
	float fInterA = fun(interA); // vycisleni funkce v bode A
	float fInterB = fun(interB); // vycisleni funkce v bode B
	float fMidd;
	float midd = vzorecRegulaFalsiSecen(interA, interB, fInterA, fInterB);
	while(fabs(fMidd = fun(midd)) >= epsilon) {
		if(maxIteraci <= 0) {
			return MAXFLOAT;
		}
		interA = interB;
		interB = midd;
		midd = vzorecRegulaFalsiSecen(interA, interB, fun(interA), fun(interB)); // jde i pomoci DO WHILE
		maxIteraci--;

	}
	return midd;
}

float vzorecNewton(float xPred, Tfun fun, Tfun funDeriv) {
	return xPred - (fun(xPred) / funDeriv(xPred));
}

float newton(float x, Tfun fun, Tfun funDeriv, float epsilon, int maxIteraci) {
	while(fabs(fun(x)) > epsilon) {
		if(maxIteraci <= 0) {
			return MAXFLOAT;
		}
		x = vzorecNewton(x, fun, funDeriv);
		maxIteraci--;
	}
	return x;
}


int main() {
	float res;
	const float epsilon = 0.001;


	res = puleniIntervaluBisekce(0.0, 2.0, f1, epsilon);
	printf("%2.3f -> Puleni interval - bisekce\n", res);  // vysledek: 1.586

	res = regulaFalsi(0.0, 2.0, f1, epsilon);
	printf("%2.3f -> Regula falsi - metoda tetiv\n", res);  // vysledek: 1.586

	// nemusi konvergovat
	res = secny(0.0, 2.0, f1, epsilon, 1000);
	printf("%2.3f -> Metoda secen\n", res);  // vysledek: 1.586

	// nemusi konvergovat
	res = newton(0, fNewton, fNewtonDeriv, 0.001, 1000);
	if(res == MAXFLOAT) {
		printf("Algoritmus [Newton] nenasel vysledek, proces byl zastaven\n");
		return EXIT_FAILURE;
	}
	printf("%2.3f -> Newton (pomoci dervaci)\n", res);  // vysledek: -0.262
	return 0;


}